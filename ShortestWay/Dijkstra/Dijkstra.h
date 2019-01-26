
#include <iostream>
#include <stack>
#include <vector>
#include "Graph.h"
#include "IndexMinHeap.h"
using namespace std;

template <typename Graph, typename Weight>
class Dijkstra
{

  private:
	Graph &G;
	int s;
	IndexMinHeap<Weight> ipq;
	vector<Edge<Weight> *> from; //from[i]记录最短路径中, 到达i点的边是哪一条
	Weight *distTo;				 //存了总权值，路径长度
	bool *marked;				 //存的是访问的最小的确定的点

  public:
	Dijkstra(Graph &graph, int s) : G(graph), ipq(IndexMinHeap<Weight>(graph.V()))
	{
		// 使用索引堆记录当前找到的到达每个顶点的最短距离

		this->s = s;
		marked = new bool[G.V()];
		distTo = new Weight[G.V()];
		for (int i = 0; i < G.V(); i++)
		{
			marked[i] = false;
			distTo[i] = Weight();
			from.push_back(NULL);
		}
		distTo[s] = Weight();
		from[s] = new Edge<Weight>(s, s, Weight());
		ipq.insert(s, distTo[s]);
		marked[s] = true;
		while (!ipq.isEmpty())
		{
			int v = ipq.extractMinIndex();
			marked[v] = true;

			typename Graph::adjIterator adj(G, v);
			for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next())
			{
				int w = e->other(v);
				if (!marked[w])
				{
					if (from[w] == NULL || distTo[v] + e->wt() < distTo[w])
						distTo[w] = distTo[v] + e->wt();
					from[w] = e;
					if (ipq.contain(w))
						ipq.change(w, distTo[w]);
					else
						ipq.insert(w, distTo[w]);
				}
			}
		}
	}

	~Dijkstra()
	{
		delete[] marked;
		delete[] distTo;
	}
	//计算最短路径的值为多少？
	Weight shortestPathTo(int w)
	{
		assert(w >= 0 && w < G.V());
		return distTo[w];
	}

	//判断是否有路径
	bool hasPathTo(int w)
	{
		assert(w >= 0 && w < G.V());
		return marked[w];
	}

	//显示s--w两点之间的最短路径包括哪些
	void shortestPath(int w, vector<Edge<Weight>> &vec)
	{
		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));
		stack<Edge<Weight> *> s;
		Edge<Weight> *e = from[w];
		while (e->w() != this->s)
		{
			s.push(e);
			e = from[e->v()];
		}
		while (!s.empty())
		{
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}
	//打印s--w最短路径的所有的边
	void showPath(int w)
	{
		vector<Edge<Weight>> vec;
		shortestPath(w, vec);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].v() << " -> ";
			if (i == vec.size() - 1)
				cout << vec[i].w() << endl;
		}
	}
};
