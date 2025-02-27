#include <iostream>
#include "deque.h"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, num;
	cin >> n;
	deque<pair<int, int>> dq(n);

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		dq.push_back(make_pair(i, num));
	}

	num = dq.front().second;
	cout << dq.front().first << ' ';

	dq.pop_front(); // ó�� ���� ǳ�� ����

	while (!dq.empty())
	{
		if (num > 0)	// +
		{
			for (int i = 0; i < num - 1; i++)	// ���� ��Ʈ�� ǳ���� front�� �ǵ��� push_back�� pop_front (num - 1) ��ŭ �ݺ�
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}

			num = dq.front().second;
			cout << dq.front().first << ' ';
			dq.pop_front();
		}
		else   // -
		{
			for (int i = 0; i > num + 1; i--)	// ������ ��� ����� �ݴ�� push_front�� pop_back
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			num = dq.back().second;
			cout << dq.back().first << ' ';
			dq.pop_back();
		}
	}

	return 0;
}