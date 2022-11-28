#include <iostream>

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

// Quick Sort
// Merge Sort의 개선판
// Pivot(중심)을 잡고, 분할
// 재귀로 반복 시, Merge 과정 없이 정렬 완성

void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	// i와 j가 CROSS 될때 까지 반복
	do
	{
		while (input[i] < pivot)		// 피벗보다 작으면 i 증가
		{
			// 왼쪽에 있으면 안되는 애들
			i++;
		}

		while (input[j] > pivot)		// 피벗보다 크면 j 감소
		{
			// 오른쪽에 있으면 안되는 애들
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);				// do while은 조건과 관계없이 
									// 일단 do 먼저 실행 후 while 조건을 봄
									// base case가 먼저 수행되지 않으므로
									// 연산을 먼저 수행 후, 종료 판단

	if (left < j)					// base case를 조건식으로 완성 1
	{
		QuickSort(input, left, j); 
	}
	if (i < right)					// base case를 조건식으로 완성 2
	{
		QuickSort(input, i, right);
	}
}

// Ot = O (c * n * log n)	QuickSort의 분할 행위 = log n, do/while 문 = c * n
// c = pivot에 의해 만들어지는 상수 (pivot의 기준은 매우 다양하므로)
// c가 n이 된다면, n^2 * logn이라는 값이 나와버린다
// 그래서 QuickSort는 Stable하지 않다

// Os = O (n)

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };
	int temp[SIZE]{};
	QuickSort(array, 0, SIZE - 1);
	PrintArray(array, SIZE);
}