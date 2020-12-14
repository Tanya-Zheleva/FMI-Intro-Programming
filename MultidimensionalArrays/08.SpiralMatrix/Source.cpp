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

void printSpiral(int matrix[][COLS], int n, int m)
{
    cout << endl;
    int currentRow = 0, currentCol = 0;

    while (currentRow < n && currentCol < m) 
    {
        for (int i = currentCol; i < m; i++) 
        {
            cout << matrix[currentRow][i] << " ";
        }

        currentRow++;

        for (int i = currentRow; i < n; i++) 
        {
            cout << matrix[i][m - 1] << " ";
        }

        m--;

        if (currentRow < n) 
        {
            for (int i = m - 1; i >= currentCol; i--) 
            {
                cout << matrix[n - 1][i] << " ";
            }

            n--;
        }

        if (currentCol < m) 
        {
            for (int i = n - 1; i >= currentRow; i--) 
            {
                cout << matrix[i][currentCol] << " ";
            }

            currentCol++;
        }
    }
}

int main()
{
	int n, m;
	cin >> n >> m;

	int matrix[ROWS][COLS] = {};
	readMatrix(matrix, n, m);

    printSpiral(matrix, n, m);

	return 0;
}