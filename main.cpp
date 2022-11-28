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
// Merge Sort�� ������
// Pivot(�߽�)�� ���, ����
// ��ͷ� �ݺ� ��, Merge ���� ���� ���� �ϼ�

void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	// i�� j�� CROSS �ɶ� ���� �ݺ�
	do
	{
		while (input[i] < pivot)		// �ǹ����� ������ i ����
		{
			// ���ʿ� ������ �ȵǴ� �ֵ�
			i++;
		}

		while (input[j] > pivot)		// �ǹ����� ũ�� j ����
		{
			// �����ʿ� ������ �ȵǴ� �ֵ�
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);				// do while�� ���ǰ� ������� 
									// �ϴ� do ���� ���� �� while ������ ��
									// base case�� ���� ������� �����Ƿ�
									// ������ ���� ���� ��, ���� �Ǵ�

	if (left < j)					// base case�� ���ǽ����� �ϼ� 1
	{
		QuickSort(input, left, j); 
	}
	if (i < right)					// base case�� ���ǽ����� �ϼ� 2
	{
		QuickSort(input, i, right);
	}
}

// Ot = O (c * n * log n)	QuickSort�� ���� ���� = log n, do/while �� = c * n
// c = pivot�� ���� ��������� ��� (pivot�� ������ �ſ� �پ��ϹǷ�)
// c�� n�� �ȴٸ�, n^2 * logn�̶�� ���� ���͹�����
// �׷��� QuickSort�� Stable���� �ʴ�

// Os = O (n)

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };
	int temp[SIZE]{};
	QuickSort(array, 0, SIZE - 1);
	PrintArray(array, SIZE);
}