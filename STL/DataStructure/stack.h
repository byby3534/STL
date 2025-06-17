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
// 헤더에서 인라인 함수로 정의 하는 이유
// 여러개의 cpp 파일에서 헤더 include선언 시 헤더를 복붙하는 방식으로 불러오기 때문에 헤더의 함수가 중복 정의 되는걸 막기 위해 inline 함수로 정의 한다.
// 즉, 동일한 함수가 중복 정의가 된다 해도 똑같은 함수로 인식할 수 있도록 하여 링크 오류를 방지하는 것이다.
template<typename T>
inline void stack<T>::resize()
{
	// 새로운 컨테이너를 만들고 새로운 컨테이너 
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