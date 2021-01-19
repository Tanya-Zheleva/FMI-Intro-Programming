#include <iostream>

using namespace std;

void print(bool** board, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (board[i][j] ? "*" : "0") << " ";
		}

		cout << endl;
	}

	cout << endl;
}

bool isFree(bool** board, int n, int i, int j)
{
	for (int k = 0; k < n; k++)
	{
		if (board[i][k] || board[k][j])
		{
			return false;
		}
	}

	return true;
}

void checkPositions(bool** board, int n, int i = 0)
{
	if (i > n)
	{
		return;
	}

	if (i == n)
	{
		print(board, n);
		return;
	}

	for (int j = 0; j < n; j++)
	{
		if (isFree(board, n, i, j))
		{
			board[i][j] = true;
			checkPositions(board, n, i + 1);
			board[i][j] = false;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	bool** board = new bool* [n];

	for (int i = 0; i < n; i++)
	{
		board[i] = new bool[n] {};
	}

	checkPositions(board, n);

	for (int i = 0; i < n; i++)
	{
		delete[] board[i];
	}

	delete[] board;

	return 0;
}