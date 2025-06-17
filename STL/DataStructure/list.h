#pragma once
// ����
// �迭�� ���Ҹ� ���� ���� �� �ڿ� �ִ� ���ҵ��� ��ĭ �� ��� �� ������ n�� �� �ð����⵵ O(n)��ŭ �ɸ���.
// �� ������ ������ ����� ���� ����Ʈ(linked list)�̴�.
// ��, �߰��� �߰� �Ǵ� ������ �ʿ䰡 �ִ� ��� ����ϴ� �ڷᱸ���̴�.(�ݴ�� �迭�� Ư�� ������ ���ٸ� �� ��� ����.)

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


// ���� ����

// ����

// ���� ����