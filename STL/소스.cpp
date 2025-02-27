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

	dq.pop_front(); // 처음 터진 풍선 제거

	while (!dq.empty())
	{
		if (num > 0)	// +
		{
			for (int i = 0; i < num - 1; i++)	// 다음 터트릴 풍선이 front가 되도록 push_back후 pop_front (num - 1) 만큼 반복
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
			for (int i = 0; i > num + 1; i--)	// 음수일 경우 양수의 반대로 push_front후 pop_back
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