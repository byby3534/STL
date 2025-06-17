#include "stdafx.h";
#include <vector>

void InsertationSort(std::vector<int>& arr)
{
	// 정렬된 인데스가 늘어날 수록 연산이 증가함
	for (int i = 1; i < arr.size(); i++) // 정렬되지 않은 인덱스 = i, 1번 인덱스부터 진행 해야함 0번은 정렬된 공간이기 때문임.
	{
		int j = i - 1;
		while (0 <= j) // 정렬된 인덱스와 비교하는 반복문
		{
			if (arr[j] > arr[i]) // 정렬된 인덱스 쪽이 더 클 경우 교체
			{
				//swap(arr, j, i);
			}
			else // 왼쪽은 이미 정렬이 되있기 때문에 한번이라도 i가 클 경우 break해야함
			{
				break;
			}
			j--;
		}
	}
}
