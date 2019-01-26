#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "ReadGraph.h"
#include "Dijkstra.h"
int main()
{
	string filename = "textG1.txt";
	int V = 5;
	/*
	 DenseGraph<double> g1(V,false); ReadGraph<DenseGraph<double>,double> readGraph1(g1, filename);
	 */
	SparseGraph<int> g2(V, true);
	ReadGraph<SparseGraph<int>, int> readGraph2(g2, filename);

	Dijkstra<SparseGraph<int>, int> dij(g2, 0);

	cout << "Test Dijkstra:" << endl
		 << endl;
	for (int i = 0; i < V; i++)
	{
		if (dij.hasPathTo(i))
			cout << "Shortest Path to " << i << ": " << dij.shortestPathTo(i) << endl,
				dij.showPath(i);
		else
			cout << "No path to " << i << endl;
		cout << "--------------------" << endl;
	}

	/*输出格式如下：
Shortest Path to 0: 0
--------------------
Shortest Path to 1: 3
0 -> 2 -> 1
--------------------
Shortest Path to 2: 2
0 -> 2
--------------------
Shortest Path to 3: 5
0 -> 2 -> 3
--------------------
Shortest Path to 4: 4
0 -> 2 -> 1 -> 4
--------------------*/
	return 0;
}