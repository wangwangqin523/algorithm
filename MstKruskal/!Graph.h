#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;
template <typename Weight>
class Edge
{
  private:
	int a;
	int b;
	Weight weight;

  public:
	Edge(int a, int b, Weight weight)
	{
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	Edge() {}
	~Edge() {}
	int v() { return a; }
	int w() { return b; }
	Weight wt() { return weight; }
	int other(int x)
	{
		return x == a ? b : a;
	}

	friend ostream &operator<<(ostream &os, const Edge &e)
	{
		os << e.a << "-" << e.b << ": " << e.weight;
		return os;
	}
	bool operator<(Edge &e)
	{
		return weight < e.weight;
	}
	bool operator<=(Edge &e)
	{
		return weight <= e.weight;
	}
	bool operator>(Edge &e)
	{
		return weight > e.weight;
	}
	bool operator>=(Edge &e)
	{
		return weight >= e.weight;
	}
	bool operator==(Edge &e)
	{
		return weight == e.weight;
	}
};
template <typename Weight>
class DenseGraph
{
  private:
	int n, m;
	bool directed;
	vector<vector<Edge<Weight> *>> g;

  public:
	DenseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
			g.push_back(vector<Edge<Weight> *>(n, NULL));
	}
	~DenseGraph()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] != NULL)
					delete g[i][j];
	}
	int V()
	{
		return n;
	}
	int E()
	{
		return m;
	}
	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		if (haveEdge(v, w))
		{
			delete g[v][w];
			if (!directed)
				delete g[w][v];
			m--;
		}

		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed)
			g[w][v] = new Edge<Weight>(w, v, weight);
		m++;
	}
	bool haveEdge(int v, int w)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		return g[v][w] != NULL;
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (g[i][j])
					cout << g[i][j]->wt() << "\t";
				else
					cout << "NULL"
						 << "\t";
			}
			cout << endl;
		}
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
		Edge<Weight> *begin()
		{
			index = -1;
			//for (int i=0;i<G.V();i++)  {if(G.g[v][i]==1) {index=i;return index;}}
			//return -1;
			return next();
		}
		Edge<Weight> *next()
		{
			index++;
			for (index; index < G.V(); index++)
			{
				if (G.g[v][index])
					return G.g[v][index];
			}
			return NULL;
		}
		bool end()
		{
			return index >= G.V();
		}
	};
};

template <typename Weight>
class SparseGraph
{
  private:
	int n, m;
	bool directed;
	vector<vector<Edge<Weight> *>> g;

  public:
	SparseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;

		for (int i = 0; i < n; i++)
			g.push_back(vector<Edge<Weight> *>());
	}
	~SparseGraph()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < g[i].size(); j++)
				if (g[i][j])
					delete g[i][j];
	}
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
	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		g[v].push_back(new Edge<Weight>(v, w, weight));
		if (v != w && !directed)
			g[w].push_back(new Edge<Weight>(w, v, weight));
		m++;
	}
	bool haveEdge(int v, int w)
	{
		assert(v >= 0 && v <= n);
		assert(w >= 0 && w <= n);
		for (int i = 0; i < g[v].size(); i++)
			if (g[v][i].other(v) == w)
				return true;
		return false;
	}

	void show()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Vertex " << i << ":\t";
			for (int j = 0; j < g[i].size(); j++)
				if (g[i][j])
					cout << "( to:" << g[i][j]->w() << ",wt:" << g[i][j]->wt() << ")\t";

			cout << endl;
		}
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
		Edge<Weight> *begin()
		{
			index = 0;
			if (G.g[v].size())
				return G.g[v][index];
			return NULL;
		}
		Edge<Weight> *next()
		{
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			return NULL;
		}
		bool end()
		{
			return index >= G.g[v].size();
		}
	};
};

template <typename Graph, typename Weight>

void show(Graph &graph)
{
	for (int v = 0; v < graph.V(); v++)
	{
		cout << " " << v << ": ";
		typename Graph::adjIterator adj(graph, v);
		Edge<Weight> *w;
		for (w = adj.begin(); !adj.end(); w = adj.next())
			cout << *w << "  ";
		cout << endl;
	}
}
