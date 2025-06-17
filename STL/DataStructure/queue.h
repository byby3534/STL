#pragma once
template<typename T>
class queue
{
private:
	T* arr;
	int capacity;
	int currentSize;
	int frontIndex;
	int rearIndex;

	void resize()
	{
		int newCapacity = capacity * 2;
		T* newArr = new T[newCapacity];

		for (int i = 0; i < currentSize; i++)
		{
			newArr[i] = arr[(frontIndex + i) % capacity];
		}

		delete[] arr;

		arr = newArr;

		frontIndex = 0;
		rearIndex = currentSize - 1;
		capacity = newCapacity;
	}

public:
	queue(int cap = 4) : capacity(cap), frontIndex(0), rearIndex(-1), currentSize(0)
	{
		arr = new T[capacity];
	}

	~queue()
	{
		delete[] arr;
	}

	void push(T data)
	{
		// 배열의 용량과 저장된 크기가 같을경우 동적 배열 확장
		if (currentSize == capacity)
			resize();

		rearIndex = (rearIndex + 1) % capacity;
		arr[rearIndex] = data;
		currentSize++;
	}

	int size()
	{
		return currentSize;
	}

	int empty()
	{
		return currentSize < 1;
	}

	T pop()
	{
		if (empty())
		{
			return -1;
		}

		currentSize--;
		T tmp = arr[frontIndex];
		frontIndex = (frontIndex + 1) % capacity;

		return tmp;
	}

	T front()
	{
		if (empty())
		{
			return -1;
		}
		return arr[frontIndex];
	}

	T back()
	{
		if (empty())
		{
			return -1;
		}
		return arr[rearIndex];
	}
};