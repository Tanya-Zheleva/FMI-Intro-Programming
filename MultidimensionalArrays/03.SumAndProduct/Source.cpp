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

void calculateSumAndProduct(int matrix[ROWS][COLS], int n, int m, int* results)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			if (matrix[row][col] > 1 && matrix[row][col] < 10000)
			{
				results[0] += matrix[row][col];
				results[1] *= matrix[row][col];
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

	cout << endl;

	int results[2] = { 0, 1 };

	calculateSumAndProduct(matrix, n, m, results);

	cout << results[0] << " " << results[1] << endl;

	return 0;
}