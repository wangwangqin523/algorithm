#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "!ReadGraph.h"
#include  "!LazyPrimeMST.h"
int main(){		
	string filename="!textG1.txt";
	 int V=8;
	 cout<<fixed<<setprecision(2);
	 DenseGraph<double> g1(V,false); ReadGraph<DenseGraph<double>,double> readGraph1(g1, filename);
	 
	SparseGraph<double> g2(V,false);
ReadGraph<SparseGraph<double>,double> readGraph2(g2, filename);
	 
	 LazyPrimMST<SparseGraph<double>,double> lazyPrimMST(g2);
	 vector<Edge<double>>mst=lazyPrimMST.mstEdges();
	 for (int i=0;i<mst.size();i++)
	 cout<<"  "<<mst[i]<<endl;
	 cout<<"  The MST weight is  "<<lazyPrimMST.result();
// show<DenseGraph<double>,double>  (g1);
 //cout<<endl;
 //show<SparseGraph<double>,double>  (g2);
 //g1.show();
//g2.show(); 

cout<<endl;
return 0;
				}