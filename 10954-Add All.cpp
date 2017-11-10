#include <iostream>
#include <vector>

using namespace std;

class Heap
{
	vector<int> heap;
public:
	Heap();
	Heap(vector<int>);
	~Heap();
	int Size();
	bool Empty();
	void Insert(int);
	int Extract();
	int Parent(int);
	int Left(int);
	int Right(int);
	void makeHeap(int);
	void Heapify(int);
	void printHeap();
};

Heap::Heap()
{
	heap.push_back(-1); // occupies index 0
}

Heap::Heap(vector<int> input)
{
	heap.push_back(-1); // occupies index 0
	for (int i = 0; i < input.size(); ++i)
	{
		heap.push_back(input[i]);
	}
}


Heap::~Heap()
{

}

int Heap::Size()
{
	return heap.size() - 1;
}

bool Heap::Empty()
{
	if(Size() == 0)
		return 1;
	return 0;
}

void Heap::Insert(int i)
{
	heap.push_back(i);
	makeHeap(Size());
}

int Heap::Extract()
{
	  int front = heap[1];
	  swap(heap[1], heap[Size()]);
	  heap.pop_back();
	  Heapify(1);
	  return front;
}

int Heap::Parent(int i)
{
	return i >> 1;
}

int Heap::Left(int i)
{
	return i << 1;
}

int Heap::Right(int i)
{
	return (i << 1) + 1;
}

void Heap::makeHeap(int i)
{
	if (i && heap[Parent(i)] > heap[i])
	{
		swap(heap[i], heap[Parent(i)]);
		makeHeap(Parent(i));
	}
}

void Heap::Heapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest;

	if (l <= Size() && heap[l] < heap[i])
		smallest = l;
	else
		smallest = i;
	if (r <= Size() && heap[r] < heap[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(heap[i], heap[smallest]);
		Heapify(smallest);
	}
}

void Heap::printHeap()
{
	for (int i = 1; i <= Size(); ++i)
	{
		cout << heap[i] << " ";
	}
}

int main()
{
	int n, num, sum, total;
	cin >> n;
	while (n != 0)
	{
		Heap myheap;
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			myheap.Insert(num);
		}
		sum = total = 0;
		//sum = myheap.Extract();
		
		while (myheap.Size() != 1)
		{
		  num = myheap.Extract();
			sum = num + myheap.Extract();

			total += sum; //add weight

			myheap.Insert(sum);
		}
		cout << total << endl;
		cin >> n;
	}
	return 0;
}
