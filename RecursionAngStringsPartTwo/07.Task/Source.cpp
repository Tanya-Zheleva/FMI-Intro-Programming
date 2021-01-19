#include <iostream>

using namespace std;

bool isValid(int n, int m, int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int countSectionSquares(int** board, int n, int m, int x, int y, int color)
{
	if (!isValid(n, m, x, y))
	{
		return 0;
	}

	if (board[x][y] != color)
	{
		return 0;
	}

	color == 0 ? board[x][y] = 1 : board[x][y] = 0;

	return 1 + countSectionSquares(board, n, m, x + 1, y, color)
		+ countSectionSquares(board, n, m, x, y + 1, color)
		+ countSectionSquares(board, n, m, x - 1, y, color)
		+ countSectionSquares(board, n, m, x, y - 1, color);
}

int countSameColorSections(int** board, int n, int m, int x, int y, int color)
{
	int sectionsCount = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == color)
			{
				sectionsCount++;
				cout << "Secton size " << countSectionSquares(board, n, m, i, j, color) << endl;
			}
		}
	}

	return sectionsCount;
}

int main()
{
	int n = 0, m, x = 0, y = 0;
	cin >> n >> m >> x >> y;

	int** board = new int* [n];

	for (int i = 0; i < n; i++)
	{
		board[i] = new int[m];

		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	//cout << countSectionSquares(board, n, m, x, y, board[x][y]) << endl;
	//cout << "Same color sections count " << countSameColorSections(board, n, m, x, y, board[x][y]) << endl;

	int color = board[x][y] ? 0 : 1;
	cout << "Different color sections count " << countSameColorSections(board, n, m, x, y, color) << endl;

	for (int i = 0; i < n; i++)
	{
		delete[] board[i];
	}

	delete[] board;

	return 0;
}