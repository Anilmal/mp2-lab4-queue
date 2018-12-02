#pragma once


const int MAX_QUEUE_SIZE = 10000;

template <class T>
class TQueue
{
	T *pMem;
	int MemSize = 0;
	int Hi = 0;
	int Li = 0;
	int DataCount = 0;
public:
	TQueue(int _size)
	{
		if (_size< 0 || _size > MAX_QUEUE_SIZE)
			throw("size is not correct");
		MemSize = _size;
		pMem = new T[MemSize];
	}
	~TQueue()
	{
		delete[] pMem;
	}
	void Add(const T &elem)
	{
		if (IsFull())
			throw ("cant add");
		pMem[Li] = elem;
		DataCount++;
		Li++;
		Li %= MemSize;
	}
	T Pop()
	{
		if (IsEmpty())
			throw "cant pop";
			
			T elem = pMem[Hi];
			DataCount--;
			Hi++;
			Hi %=  MemSize;
			return elem;
	}
	bool IsEmpty()
	{
		return DataCount == 0;
	}
	bool IsFull()
	{
		return DataCount == MemSize;
	}
	T Get()
	{
		return pMem[Hi];
	}
};