#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;
class DenseGraph
{
  private:
	int n, m;
	bool directed;
	vector<vector<bool>> g;

  public:
	DenseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
			g.push_back(vector<bool>(n, false));
	}
	~DenseGraph() {}
	int V()
	{
		return n;
	}
	int E()
	{
		return m;
	}
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		if (haveEdge(v, w))
			return;
		g[v][w] = true;
		if (!directed)
			g[w][v] = true;
		m++;
	}
	bool haveEdge(int v, int w)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		return g[v][w];
	}
	class adjIterator
	{
	  private:
		DenseGraph &G;
		int v;
		int index;

	  public:
		adjIterator(DenseGraph &graph, int v) : G(graph)
		{
			this->v = v;
			this->index = -1;
		}
		int begin()
		{
			index = -1;
			for (int i = 0; i < G.V(); i++)
			{
				if (G.g[v][i] == 1)
				{
					index = i;
					return index;
				}
			}
			return -1;
			//return next();
		}
		int next()
		{
			index++;
			for (index; index < G.V(); index++)
			{
				if (G.g[v][index] == 1)
					return index;
			}
			return -1;
		}
		bool end()
		{
			return index >= G.V();
		}
	};
};

class SparseGraph
{
  private:
	int n, m;
	bool directed;
	vector<vector<int>> g;

  public:
	SparseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;

		for (int i = 0; i < n; i++)
			g.push_back(vector<int>());
	}
	~SparseGraph() {}
	void visit(int v)
	{
		for (int i = 0; i < g[v].size(); i++)
			cout << g[v][i] << "  ";
	}
	int V()
	{
		return n;
	}
	int E()
	{
		return m;
	}
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		//	if (haveEdge(v,w))  return;
		g[v].push_back(w);
		if (v != w && !directed)
			g[w].push_back(v);
		m++;
	}
	bool haveEdge(int v, int w)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		for (int i = 0; i < g[v].size(); i++)
			if (g[v][i] == w)
				return true;
		return false;
	}
	class adjIterator
	{
	  private:
		SparseGraph &G;
		int v;
		int index;

	  public:
		adjIterator(SparseGraph &graph, int v) : G(graph)
		{
			this->v = v;
			this->index = 0;
		}
		int begin()
		{
			index = 0;
			if (G.g[v].size())
				return G.g[v][index];
			return -1;
		}
		int next()
		{
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			return -1;
		}
		bool end()
		{
			return index >= G.g[v].size();
		}
	};
};

template <typename Graph>
void show(Graph &graph)
{
	for (int v = 0; v < graph.V(); v++)
	{
		cout << " " << v << ": ";
		typename Graph::adjIterator adj(graph, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << "  ";
		cout << endl;
	}
}

template <typename Graph>
class Component
{
  private:
	Graph &G;
	bool *visited;
	int ccount;

	void dfs(int v)
	{
		visited[v] = true;
		cout << " " << v;
		typename Graph::adjIterator adj(G, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
		{
			if (!visited[w])
				dfs(w);
		}
	}

	void level(int v)
	{
		queue<int> q;

		q.push(v);
		while (!q.empty())
		{
			int i = q.front();
			visited[i] = true;
			cout << " " << i;
			q.pop();
			typename Graph::adjIterator adj(G, i);
			for (int w = adj.begin(); !adj.end(); w = adj.next())
			{
				if (!visited[w])
					q.push(w), visited[w] = true;
			}
		}
	}

  public:
	Component(Graph &graph) : G(graph)
	{
		bool k[G.V()];
		visited = k;
		ccount = 0;
		for (int i = 0; i < G.V(); i++)
			visited[i] = false;
		for (int i = 0; i < G.V(); i++)
		{
			if (!visited[i])
			{
				dfs(i);
				ccount++;
			}
		}
	}
	~Component() {}
	int count()
	{
		return ccount;
	}

	void path(int v, int j)
	{
		bool k[G.V()];
		visited = k;
		ccount = 0;
		for (int i = 0; i < G.V(); i++)
			visited[i] = false;
		queue<int> q;
		q.push(v);
		while (!q.empty())
		{
			int i = q.front();
			visited[i] = true;
			cout << " " << i;
			if (i == j)
				return;
			q.pop();
			typename Graph::adjIterator adj(G, i);
			for (int w = adj.begin(); !adj.end(); w = adj.next())
			{
				if (!visited[w])
					q.push(w), visited[w] = true;
			}
		}
	}
};
