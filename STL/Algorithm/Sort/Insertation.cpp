#include "stdafx.h";
#include <vector>

void InsertationSort(std::vector<int>& arr)
{
	// ���ĵ� �ε����� �þ ���� ������ ������
	for (int i = 1; i < arr.size(); i++) // ���ĵ��� ���� �ε��� = i, 1�� �ε������� ���� �ؾ��� 0���� ���ĵ� �����̱� ������.
	{
		int j = i - 1;
		while (0 <= j) // ���ĵ� �ε����� ���ϴ� �ݺ���
		{
			if (arr[j] > arr[i]) // ���ĵ� �ε��� ���� �� Ŭ ��� ��ü
			{
				//swap(arr, j, i);
			}
			else // ������ �̹� ������ ���ֱ� ������ �ѹ��̶� i�� Ŭ ��� break�ؾ���
			{
				break;
			}
			j--;
		}
	}
}
