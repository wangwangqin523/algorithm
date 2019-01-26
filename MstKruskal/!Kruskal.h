
#include <iostream>
#include <vector>
#include "!Graph.h"
#include "MinHeap.h"
#include "UnionFindHelper.h"
using namespace std;

template <typename Graph, typename Weight>
class KruskalMST
{

  private:
	Graph &G;
	MinHeap<Edge<Weight>> pq;
	vector<Edge<Weight>> mst;
	Weight mstWeight;

  public:
	KruskalMST(Graph &graph) : G(graph), pq(MinHeap<Edge<Weight>>(G.E()))
	{
		unionFind2 uf(G.V());
		mst.clear();
		for (int v = 0; v < G.V(); v++)
		{
			typename Graph::adjIterator adj(G, v);
			for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next())
				if (e->w() > e->v())
					pq.insert(*e);
		}

		while (!pq.isEmpty() && mst.size() <= G.V() - 1)
		{
			Edge<Weight> e = pq.extractMin();
			if (uf.isConnected(e.v(), e.w()))
				//	 			if(uf.find(e.v())==uf.find(e.w()))
				continue;
			uf.unionElements(e.v(), e.w());

			mst.push_back(e);
		}
		mstWeight = 0;
		for (int i = 0; i < mst.size(); i++)
			mstWeight += mst[i].wt();
	}

	~KruskalMST()
	{
	}
	vector<Edge<Weight>> mstEdges() { return mst; }
	Weight result()
	{
		return mstWeight;
	}
};
