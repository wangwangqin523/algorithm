#include "UnionFindHelper.h"
unionFind2::unionFind2(int n)
{
	count = n;
	id = new int[n];
	rank = new int[n];
	for (int i = 0; i < n; i++)
		id[i] = i, rank[i] = 1;
}

unionFind2::~unionFind2()
{
	delete[] id;
	delete[] rank;
}
int unionFind2::find(int p)
{
	assert(p >= 0 && p < count);
	while (id[p] != p)
	{
		id[p] = id[id[p]];
		p = id[p];
	}

	return p;
}

void unionFind2::unionElements(int p, int q)
{

	int pID = find(p);
	int qID = find(q);
	if (pID == qID)
		return;
	if (rank[pID] > rank[qID])
		id[qID] = pID;
	else if (rank[pID] > rank[qID])
		id[pID] = qID;
	else
		id[pID] = qID, rank[qID]++;
}
