#include <iostream>

using namespace std;

typedef int(*map)(int);

int addFive(int x)
{
	return x + 5;
}

int addThree(int x)
{
	return x + 7;
}

void transform(int** matrix, int n, int row, int col, map f, map g)
{
	row >= col
		? matrix[row][col] = f(matrix[row][col])
		: matrix[row][col] = g(matrix[row][col]);

	if (col == n - 1)
	{
		if (row == n - 1)
		{
			return;
		}
		else
		{
			transform(matrix, n, row + 1, 0, f, g);
		}
	}
	else
	{
		transform(matrix, n, row, col + 1, f, g);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << endl;
	transform(matrix, n, 0, 0, addFive, addThree);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << ' ';
		}

		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}