#include <iostream>

using namespace std;

const int ROWS = 50;
const int COLS = 50;

void readMatrix(int matrix[][COLS], int n, int m)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

int compareTo(int* rowA, int* rowB, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		if (rowA[i] < rowB[i])
		{
			return -1;
		}
		else if (rowA[i] > rowB[i])
		{
			return 1;
		}
	}

	return 0;
}

void swapRows(int* rowA, int* rowB, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		int temp = rowA[i];
		rowA[i] = rowB[i];
		rowB[i] = temp;
	}
}

void sortMatrix(int matrix[][COLS], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int minRow = i;

		for (int j = i + 1; j < n; j++)
		{
			int compareIndex = compareTo(matrix[minRow], matrix[j], m);

			if (compareIndex > 0)
			{
				minRow = j;
			}
		}

		if (minRow != i)
		{
			swapRows(matrix[minRow], matrix[i], m);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

	sortMatrix(matrix, n, m);

	cout << endl;

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			cout << matrix[row][col] << " ";
		}

		cout << endl;
	}

	return 0;
}