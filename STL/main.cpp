#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr = { 5, 9, 4, 1, 3, 6, 8, 2, 7 };
	InsertationSort(arr);

	for (int i : arr)
	{
		cout << i << " ";
	}
	return 0;
}