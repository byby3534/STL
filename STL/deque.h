#pragma once
#include <iostream>
using namespace std;
// 1. ���� �迭 : �Ϲ� �迭�� ��� push_front�� �ϰ� �� ��� ��簪�� ��ĭ �� �̷�� �ϱ� ������ O(n)�� �ð� ���⵵�� ������ �� �̸� �����ϱ� ���� �ð����⵵�� O(1)�� ���� �迭�� ����� ���� ���� �迭�� �ε��� ȣ�� �� ��� ���ϴ� ���� �ҷ����� ��ƴٴ� �������� ���� �׷��� �̸� �����ϱ� ���� ���߿��Ḯ��Ʈ ����� �����
template<typename T>
class deque
{
private:
	T* container;
	int capacity;
	int head;
	int tail;
	int curSize;
	void resize();
public:
	deque(int cap = 4);
	~deque();
	void push_front(T data);
	void push_back(T data);
	int size();
	int empty();
	bool isFull();
	T pop_front();
	T pop_back();
	T front();
	T back();
	void displayDetail();
};

template<typename T>
inline void deque<T>::resize()
{
	int newCapacity = capacity * 2;
	T* newContainer = new T[newCapacity];
	int prevSize = this->size();
	for (int i = 0; i < prevSize; i++)
	{
		newContainer[i] = container[(head + i) % capacity];
	}
	delete[] container;

	container = newContainer;
	capacity = newCapacity;
	head = 0;
	tail = prevSize;
}

template<typename T>
inline deque<T>::deque(int cap) : capacity(cap), head(0), tail(0), curSize(0)
{
	container = new T[capacity]();
}

template<typename T>
inline deque<T>::~deque()
{
	delete[] container;
}


template<typename T>
inline void deque<T>::push_front(T data)
{
	if (isFull())
		resize();
	
	head = (head - 1 + capacity) % capacity;
	container[head] = data;
	curSize++;
}

template<typename T>
inline void deque<T>::push_back(T data)
{
	if (isFull())
		resize();

	container[tail] = data;
	tail = (tail + 1) % capacity;
	curSize++;
}

template<typename T>
inline int deque<T>::size()
{
	return curSize;
}


template<typename T>
inline int deque<T>::empty()
{
	return curSize == 0;
}

template<typename T>
inline bool deque<T>::isFull()
{
	return curSize == capacity;
}

template<typename T>
inline T deque<T>::pop_front()
{
	if (empty())
	{
		return T();
	}
	T tmpData = container[head];
	head = (head + 1) % capacity;
	curSize--;
	return tmpData;
}

template<typename T>
inline T deque<T>::pop_back()
{
	if (empty())
	{
		return T();
	}

	tail = (tail - 1 + capacity) % capacity;
	curSize--;
	return container[tail];
}

template<typename T>
inline T deque<T>::front()
{
	if (empty())
	{
		return T();
	}
	return container[head];
}

template<typename T>
inline T deque<T>::back()
{
	if (empty())
	{
		return T();
	}
	return container[(tail - 1 + capacity) % capacity];
}

template<typename T>
inline void deque<T>::displayDetail()
{
	cout << "Cap   : " << capacity << '\n';
	cout << "Size  : " << size() << '\n';
	cout << "Data  : ";
	for (int i = head; i < head + curSize; i++)
	{
		if constexpr(is_same_v<T, pair<int, int>>)
		{
			cout << "[(" << container[i % capacity].first << ", "
				<< container[i % capacity].second << ")] ";
		}
		else
		{
			cout << "[" << container[i % capacity] << "]";
		}
	}

	cout << '\n' << "Index : ";
	for (int i = head; i < head + curSize; i++)
	{
		cout << '[' << i % capacity << ']';
	}

	cout << '\n' << "head  : " << head << '\n' << "tail  : " << tail << '\n';
}
