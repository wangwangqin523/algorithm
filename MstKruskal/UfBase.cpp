#include "ufBase.h"
bool unionFind::isConnected(int p, int q)
{
	return find(p) == find(q);
}
