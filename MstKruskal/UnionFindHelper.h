#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include "ufBase.h"
using namespace std;

class unionFind2 : public unionFind
{ //Quick Union
  protected:
	int *rank; //base on the
  public:
	unionFind2(int n);
	~unionFind2();
	virtual int find(int p);
	void unionElements(int p, int q);
};

class unionFind2r : public unionFind2
{
	int find(int p)
	{
		if (id[p] != p)
			id[p] = find(id[p]);
		return id[p];
	}
};

template <typename UF>
void testUF(int n)
{
	UF uf;
	srand(time(NULL));
	time_t startTime = clock();
	for (int i = 0; i < n; i++)
	{
		int a = rand() % n;
		int b = rand() % n;
		uf.unionElements(a, b);
	}
	for (int i = 0; i < n; i++)
	{
		int a = rand() % n;
		int b = rand() % n;
		uf.isConnected(a, b);
	}
	time_t endTime = clock();
	cout << "\t" << double(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;
}
