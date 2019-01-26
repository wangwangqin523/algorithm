#include <iostream>
#include <cassert>
using namespace std;

template <typename Item>
class MinHeap
{
  private:
	Item *data;
	int count;
	int capacity;
	void shiftUp(int k)
	{

		while (k > 1)
		{
			int p = k / 2;
			if (data[k] < data[p])
				swap(data[k], data[p]), k = p;
			else
				break;
		}
	}

	void shiftDown(int k)
	{
		while (2 * k <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] < data[j])
				j = j + 1;
			if (data[k] <= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}

  public:
	MinHeap(int capacity)
	{
		data = new Item[capacity + 1];
		count = 0;
	}

	~MinHeap()
	{
		delete[] data;
	}
	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void insert(Item item)
	{
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}

	Item extractMin()
	{
		assert(count >= 1);
		Item ret = data[1];
		data[1] = data[count];
		count--;
		shiftDown(1);
		return ret;
	}

	void testPrint()
	{
		for (int i = 1; i <= count; i++)
			cout << data[i] << "   ";
	}
};
