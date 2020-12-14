#include <iostream>

using namespace std;

const int ROWS = 50;
const int COLS = 50;

void swapNumbers(int& a, int& b)
{
	int temp = a;
	a = b;
	b = a;
}

void readMatrix(int matrix[][COLS], int n)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

void transpose(int matrix[][COLS], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int matrix[ROWS][COLS] = {};

	readMatrix(matrix, n);
	transpose(matrix, n);

	cout << endl;

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cout << matrix[row][col] << " ";
		}

		cout << endl;
	}

	return 0;
}