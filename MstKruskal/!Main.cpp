#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "!ReadGraph.h"
#include "!Kruskal.h"
using namespace std;
int main()
{
	string filename = "!textG1.txt";
	int V = 8;
	cout << fixed << setprecision(2);
	DenseGraph<double> g1(V, false);
	ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);

	SparseGraph<double> g2(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);

	KruskalMST<SparseGraph<double>, double> kruskalMST(g2);
	vector<Edge<double>> mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << "  " << mst[i] << endl;
	cout << "  The MST weight is  " << kruskalMST.result();
	// show<DenseGraph<double>,double>  (g1);
	//cout<<endl;
	//show<SparseGraph<double>,double>  (g2);
	//g1.show();
	//g2.show();

	cout << endl;
	return 0;
}
