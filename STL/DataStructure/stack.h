#pragma once
template<typename T>
class stack
{
private:
	T* container;
	int topIndex;
	int capacity;

	void resize();
public:
	stack(int cap = 4);
	~stack();

	void push(T data);
	int empty();
	int size();
	T pop();
	T top();
};
// ������� �ζ��� �Լ��� ���� �ϴ� ����
// �������� cpp ���Ͽ��� ��� include���� �� ����� �����ϴ� ������� �ҷ����� ������ ����� �Լ��� �ߺ� ���� �Ǵ°� ���� ���� inline �Լ��� ���� �Ѵ�.
// ��, ������ �Լ��� �ߺ� ���ǰ� �ȴ� �ص� �Ȱ��� �Լ��� �ν��� �� �ֵ��� �Ͽ� ��ũ ������ �����ϴ� ���̴�.
template<typename T>
inline void stack<T>::resize()
{
	// ���ο� �����̳ʸ� ����� ���ο� �����̳� 
	capacity *= 2;
	T* tmpContainer = new T[capacity];
	for (int i = 0; i <= topIndex; i++)
	{
		tmpContainer[i] = container[i];
	}
	delete[] container;
	container = tmpContainer;
}

template<typename T>
inline stack<T>::stack(int cap) : topIndex(-1), capacity(cap)
{
	container = new T[capacity];
}

template<typename T>
inline stack<T>::~stack()
{
	delete[] container;
}

template<typename T>
inline void stack<T>::push(T data)
{
	if (topIndex + 1 == capacity) 
		resize();

	container[++topIndex] = data;
}

template<typename T>
inline int stack<T>::empty()
{
	return topIndex < 0;
}

template<typename T>
inline int stack<T>::size()
{
	return topIndex + 1;
}

template<typename T>
inline T stack<T>::pop()
{
	if (empty())
	{
		return -1;
	}
	return container[topIndex--];
}

template<typename T>
inline T stack<T>::top()
{
	if (empty())
	{
		return -1;
	}
	return container[topIndex];
}