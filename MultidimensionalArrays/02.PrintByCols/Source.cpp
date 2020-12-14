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

void printByCols(int matrix[ROWS][COLS], int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[j][i] << " ";
		}

		cout << endl;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

	cout << endl;

	printByCols(matrix, n, m);

	return 0;
}