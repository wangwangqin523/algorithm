#include <iostream>
#include <cassert>
using namespace std;

template <typename Item>
class IndexMinHeap
{
  private:
	Item *data;
	int *indexes;
	int *reverse;
	int count;
	int capacity;
	void shiftUp(int k)
	{

		while (k > 1)
		{
			int p = k / 2;
			if (data[indexes[k]] < data[indexes[p]])
				swap(indexes[k], indexes[p]),
					reverse[indexes[k]] = k, reverse[indexes[p]] = p, k = p;
			else
				break;
		}
	}

	void shiftDown(int k)
	{
		while (2 * k <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && data[indexes[j + 1]] < data[indexes[j]])
				j = j + 1;
			if (data[indexes[k]] <= data[indexes[j]])
				break;
			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	}

  public:
	IndexMinHeap(int n)
	{
		data = new Item[n + 1];
		indexes = new int[n + 1];
		reverse = new int[n + 1];
		for (int i = 0; i <= n; i++)
			reverse[i] = 0;

		count = 0;
		this->capacity = n;
	}

	~IndexMinHeap()
	{
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}
	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	//对于用户数组i下标是从0开始的
	void insert(int i, Item item)
	{
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);
		i++;
		data[i] = item;
		indexes[count + 1] = i;
		reverse[i] = count + 1;
		count++;
		shiftUp(count);
	}

	Item extractMin()
	{
		assert(count >= 1);
		Item ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);
		return ret;
	}
	int extractMinIndex()
	{
		assert(count >= 1);
		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	bool contain(int i)
	{
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}
	Item getItem(int i)
	{
		assert(contain(i));
		return data[i + 1];
	}
	void change(int i, Item newItem)
	{
		assert(contain(i));
		i++;
		data[i] = newItem;
		//找到indexes[j]==i表示j在data[i]在堆中位置

		int j = reverse[i];
		shiftDown(j), shiftUp(j);
		return;
	}

	void testPrint()
	{
		int k = count;
		for (int i = 1; i <= k; i++)
			cout << extractMin() << "   ";
	}
};
