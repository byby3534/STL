#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, num;
	cin >> n;
	int* dataStructure = new int[n];
	deque<int> queueStack;
	
	// 자료구조 입력
	for (int i = 0; i < n; i++)
	{
		cin >> dataStructure[i];
	}

	// 초기 숫자 입력
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		// 스택은 존재하지 않아도 결과에 영향이 없음 그러므로 큐일 때만 숫자 입력
		if (dataStructure[i] == 0)
		{
			queueStack.push_front(num);
		}
	}

	cin >> n;
	// 0 = 큐, 1 = 스택
	// 큐는 선입선출 구조로 먼저있던게 빠지기 때문에 변화가 있음 반대로 스택은 후입 선출 구조기 때문에 변화가 없음
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		queueStack.push_back(num);
		cout << queueStack.front() << ' ';
		queueStack.pop_front();
	}

	delete[] dataStructure;
	return 0;
}