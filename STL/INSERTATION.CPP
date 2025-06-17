#include "stdafx.h";
#include <vector>

void InsertationSort(std::vector<int>& arr)
{
	// 정렬된 인데스가 늘어날 수록 연산이 증가함
	for (int i = 1; i < arr.size(); i++) // 정렬되지 않은 인덱스 = i, 1번 인덱스부터 진행 해야함 0번은 정렬된 공간이기 때문임.
	{
		int key = arr[i]; // 검사할 값 저장
		int j = i - 1; // 정렬된 인덱스 값
		while (0 <= j && arr[j] > key) // 정렬된 인덱스와 비교하는 반복문
		{
			arr[j + 1] = arr[j]; // 오른쪽으로 값 이동
			j--;
		}
		arr[j + 1] = key;
	}
}