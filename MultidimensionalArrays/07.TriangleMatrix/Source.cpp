#include <iostream>

using namespace std;

const int ROWS = 50;
const int COLS = 50;

void readMatrix(int matrix[ROWS][COLS], int n)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

bool hasZerosAboveMainDiagonal(int matrix[ROWS][COLS], int n)
{
	for (int row = 0; row < n - 1; row++)
	{
		for (int col = row + 1; col < n; col++)
		{
			if (matrix[row][col] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool hasZerosBelowMainDiagonal(int matrix[ROWS][COLS], int n)
{
	for (int row = 1; row < n; row++)
	{
		for (int col = 0; col < row; col++)
		{
			if (matrix[row][col] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool hasZerosAboveSecondaryDiagonal(int matrix[ROWS][COLS], int n)
{
	for (int row = 0; row < n - 1; row++)
	{
		for (int col = 0; col < n - row - 1; col++)
		{
			if (matrix[row][col] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool hasZerosBelowSecondaryDiagonal(int matrix[ROWS][COLS], int n)
{
	for (int row = n - 1; row > 0; row--)
	{
		for (int col = n - row; col < n; col++)
		{
			if (matrix[row][col] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int n;
	cin >> n;
	int matrix[ROWS][COLS] = {};

	readMatrix(matrix, n);

	if (hasZerosAboveMainDiagonal(matrix, n) ||
		hasZerosBelowMainDiagonal(matrix, n) ||
		hasZerosAboveSecondaryDiagonal(matrix, n) ||
		hasZerosBelowSecondaryDiagonal(matrix, n))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	return 0;
}