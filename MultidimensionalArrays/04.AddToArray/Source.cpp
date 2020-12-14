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

int getRowSum(int* row, int cols)
{
	int sum = 0;

	for (int col = 0; col < cols; col++)
	{
		sum += row[col];
	}

	return sum;
}

int getRowProduct(int* row, int cols)
{
	int product = 1;

	for (int col = 0; col < cols; col++)
	{
		product *= row[col];
	}

	return product;
}

void addToArray(int matrix[ROWS][COLS], int n, int m, int* arr)
{
	for (int row = 0; row < n; row++)
	{
		int result = row % 2 == 0 ? getRowSum(matrix[row], m) : getRowProduct(matrix[row], m);
		arr[row] = result;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

	cout << endl;

	int arr[ROWS] = {};

	addToArray(matrix, n, m, arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}