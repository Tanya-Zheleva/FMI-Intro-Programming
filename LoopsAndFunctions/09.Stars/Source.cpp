#include <iostream>
#include <iomanip> 

using namespace std;

void printRow(int limit, int spaces)
{
	cout << setw(spaces);

	for (int j = 0; j < limit; j++)
	{
		cout << "*" << " ";
	}
}

int main()
{
	int n;
	cin >> n;

	int height = 2 * n - 1;

	for (int i = 1; i <= height; i++)
	{
		i <= n
			? printRow(i, n - i + 1)
			: printRow(height - i + 1, i - n + 1);

		cout << endl;
	}

	return 0;
}