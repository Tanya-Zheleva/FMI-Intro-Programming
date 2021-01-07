#include <iostream>

using namespace std;

bool isValid(char** lab, int n, int m, bool** visited, int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && lab[x][y] == '.';
}

bool solveUntil(char** lab, int n, int m, bool** visited, int x, int y)
{
	if (x == n - 1 && y == m - 1 && lab[x][y] == '.')
	{
		return true;
	}

	if (isValid(lab, n, m, visited, x, y))
	{
		visited[x][y] = true;

		if (solveUntil(lab, n, m, visited, x - 1, y))
		{
			return true;
		}

		if (solveUntil(lab, n, m, visited, x, y + 1))
		{
			return true;
		}

		if (solveUntil(lab, n, m, visited, x + 1, y))
		{
			return true;
		}

		if (solveUntil(lab, n, m, visited, x, y - 1))
		{
			return true;
		}

		visited[x][y] = false;

		return false;
	}

	return false;
}

bool solve(char** lab, int n, int m)
{
	bool** visited = new bool* [n];

	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m] {};
	}

	bool result = solveUntil(lab, n, m, visited, 0, 0);

	for (int i = 0; i < n; i++)
	{
		delete[] visited[i];
	}

	delete[] visited;

	return result;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	char** lab = new char* [n];

	for (int i = 0; i < n; i++)
	{
		lab[i] = new char[m];

		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
		}
	}

	cout << boolalpha << solve(lab, n, m) << endl;

	for (int i = 0; i < n; i++)
	{
		delete[] lab[i];
	}

	delete[] lab;

	return 0;
}