#include <iostream>

using namespace std;

void printCol(int n, bool leftSideSpace)
{
	for (int i = 0; i < n; i++)
	{
		leftSideSpace
			? cout << " |"
			: cout << "| ";
	}
}

void printRow(int n)
{
	cout << ">";

	for (int i = 0; i < n; i++)
	{
		cout << "_";
	}

	cout << "<";
}

int main()
{
	int n;
	cin >> n;

	int height = 2 * (n - 1) + 2;

	for (int i = 0; i < height; i++)
	{
		if (i < n )
		{
			int limit = 4 * (n - i - 1) + 1;

			printCol(i, false);
			printRow(limit);
			printCol(i, true);
		}
		else
		{
			int colsCount = height - i - 1;
			int limit = 4 * (i - n) + 1;

			printCol(colsCount, false);
			printRow(limit);
			printCol(colsCount, true);
		}

		cout << endl;
	}
}