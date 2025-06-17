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
	
	// �ڷᱸ�� �Է�
	for (int i = 0; i < n; i++)
	{
		cin >> dataStructure[i];
	}

	// �ʱ� ���� �Է�
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		// ������ �������� �ʾƵ� ����� ������ ���� �׷��Ƿ� ť�� ���� ���� �Է�
		if (dataStructure[i] == 0)
		{
			queueStack.push_front(num);
		}
	}

	cin >> n;
	// 0 = ť, 1 = ����
	// ť�� ���Լ��� ������ �����ִ��� ������ ������ ��ȭ�� ���� �ݴ�� ������ ���� ���� ������ ������ ��ȭ�� ����
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