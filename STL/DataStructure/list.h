#pragma once
// 단일
// 배열은 원소를 제거 했을 때 뒤에 있는 원소들을 한칸 씩 당겨 그 개수가 n일 때 시간복잡도 O(n)만큼 걸린다.
// 이 단점을 보완한 방식이 연결 리스트(linked list)이다.
// 즉, 중간에 추가 또는 삭제할 필요가 있는 경우 사용하는 자료구조이다.(반대로 배열은 특정 원소의 접근만 할 경우 좋다.)

template<typename T>
class forward_list
{
private:
	Node* head;
	
public:
	struct Node
	{
		T data;
		Node* next;
	};

	forward_list();
	~forward_list();

	void push_front(T data);
	int empty();
	T pop_front();

	T front();
};

template<typename T>
inline forward_list<T>::forward_list() : head(nullptr)
{
}

template<typename T>
inline forward_list<T>::~forward_list()
{
}

template<typename T>
inline void forward_list<T>::push_front(T data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head->next;	// newNode->next = curNode
	head->next = newNode;		// head->next = newNode
}

template<typename T>
inline int forward_list<T>::empty()
{
	return head == nullptr;
}

template<typename T>
inline T forward_list<T>::pop_front()
{
	if (empty())
	{
		return T();
	}
	Node* tmpNode = head->next;
	head->next = head->next->next;
	delete tmpNode;
	return 
}

template<typename T>
inline T forward_list<T>::front()
{
	return T();
}


// 단일 원형

// 이중

// 이중 원형