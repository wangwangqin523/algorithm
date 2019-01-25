#include <iostream>
#include <cstdlib>
#include "Graph.h"
#include <ctime>
#include <ReadGraph.h>
int main(){
/*	int N=20;
	int M=100;
	srand(time(NULL));
	
	SparseGraph g1(N ,false);
	DenseGraph  g2(N,false);
	for (int i=0;i<M;i++)
	{
		int a =rand()%N;
		int b=rand()%N;
		g1.addEdge(a,b);
		g2.addEdge(a,b);
		}
for (int v=0;v<N;v++){
	cout<<" "<<v<<": ";
	typename SparseGraph::adjIterator adj(g1,v);
	for (int w= adj.begin();!adj.end();w=adj.next())
	cout<<w<<"  ";
	cout<<endl;
	}
for (int v=0;v<N;v++){
		cout<<" "<<v<<": ";
	typename DenseGraph::adjIterator adj(g2,v);
	for (int w= adj.begin();!adj.end();w=adj.next())
	cout<<w<<"  ";
	cout<<endl;
	}*/
	
	string filename="textG1.txt";
	 SparseGraph g1(13,false);
	 
	 ReadGraph<SparseGraph> readGraph1(g1, filename);
//	 show<SparseGraph>(g1);
 Component<SparseGraph> component1(g1);
cout<<endl;
		component1.path(0,1);
	 cout<<endl<<"   "<<component1.count();
return 0;
				}