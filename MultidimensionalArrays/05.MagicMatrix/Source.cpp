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

int getMainDiagonalProduct(int matrix[ROWS][COLS], int n)
{
	int product = 1;

	for (int i = 0; i < n; i++)
	{
		product *= matrix[i][i];
	}

	//1 2 3 4 [0,0]
	//4 5 6 4 [1,1]
	//1 2 3 4 [2,2]
	//0 2 1 9 [3,3] n = 4

	return product;
}

int getSecondaryDiagonalProduct(int matrix[ROWS][COLS], int n)
{
	int product = 1;

	for (int row = 0; row < n; row++)
	{
		int col = n - 1 - row;
		product *= matrix[row][col];
	}

	//1 2 3 4 [0,3]
	//4 5 6 4 [1,2]
	//1 2 3 4 [2,1]
	//0 2 1 9 [3,0] n = 4

	return product;
}

bool hasMagicCols(int matrix[ROWS][COLS], int n)
{
	int magicProduct = getMainDiagonalProduct(matrix, n);

	for (int col = 0; col < n; col++)
	{
		int product = 1;

		for (int row = 0; row < n; row++)
		{
			product *= matrix[row][col];
		}

		if (product != magicProduct)
		{
			return false;
		}
	}

	return true;
}

bool hasMagicRows(int matrix[ROWS][COLS], int n)
{
	int magicProduct = getMainDiagonalProduct(matrix, n);

	for (int row = 0; row < n; row++)
	{
		int product = 1;

		for (int col = 0; col < n; col++)
		{
			product *= matrix[row][col];
		}

		if (magicProduct != product)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int n;
	cin >> n;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, n);

	if (getMainDiagonalProduct(matrix, n) == getSecondaryDiagonalProduct(matrix, n) && hasMagicRows(matrix, n) && hasMagicCols(matrix, n))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	return 0;
}