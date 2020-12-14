#include <iostream>

using namespace std;

const int ROWS = 50;
const int COLS = 50;

void readMatrix(int matrix[ROWS][COLS], int n, int m)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

int getSubMatrixSum(int matrix[ROWS][COLS], int startRow, int startCol, int p, int q)
{
	int sum = 0;

	for (int row = startRow; row < startRow + p; row++)
	{
		for (int col = startCol; col < startCol + q; col++)
		{
			sum += matrix[row][col];
		}
	}

	return sum;
}

int getMaxSubMatrixSum(int matrix[ROWS][COLS], int n, int m, int p, int q)
{
	int maxSum = getSubMatrixSum(matrix, 0, 0, p, q);
	int rowLimit = n - p + 1;
	int colLimit = m - q + 1;

	for (int row = 0; row < rowLimit; row++)
	{
		for (int col = 0; col < colLimit; col++)
		{
			int currentSum = getSubMatrixSum(matrix, row, col, p, q);

			if (currentSum > maxSum)
			{
				maxSum = currentSum;
			}
		}
	}

	return maxSum;
}

int main()
{
	int n, m, p, q;
	cin >> n >> m;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

	cin >> p >> q;

	cout << getMaxSubMatrixSum(matrix, n, m, p, q) << endl;

	return 0;
}