#include <iostream>

using namespace std;

const int ROWS = 50;
const int COLS = 50;

void readMatrix(double matrix[ROWS][COLS], int n, int m)
{
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

double getMax(double matrix[ROWS][COLS], int n, int m)
{
	double max = matrix[0][0];

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			if (max < matrix[row][col])
			{
				max = matrix[row][col];
			}
		}
	}

	return max;
}

int main()
{
	int n, m;
	cin >> n >> m;

	double matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

	cout << getMax(matrix, n, m) << endl;

	return 0;
}