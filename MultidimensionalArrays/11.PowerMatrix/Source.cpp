#include <iostream>

using namespace std;

const int ROWS = 20;
const int COLS = 20;

void readMatrix(long long matrix[][COLS], int n)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

void printMatrix(long long matrix[][COLS], int n)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cout << matrix[row][col] << " ";
		}

		cout << endl;
	}
}

void copyTo(long long source[][COLS], long long destination[][COLS], int n)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			destination[row][col] = source[row][col];
		}
	}
}

void toPower(long long matrix[][COLS], long long result[][COLS], int n, int power) {
	for (int i = 1; i < power; i++)
	{
		long long product[ROWS][COLS] = { };

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				for (int inner = 0; inner < n; inner++) {
					product[row][col] += result[row][inner] * matrix[inner][col];
				}
			}
		}

		copyTo(product, result, n);
	}
}

int main()
{
	int n, power;
	cin >> n >> power;

	long long matrix[ROWS][COLS] = {};
	long long result[ROWS][COLS] = {};

	readMatrix(matrix, n);

	copyTo(matrix, result, n);

	toPower(matrix, result, n, power);
	cout << endl;

	printMatrix(result, n);

	return 0;
}