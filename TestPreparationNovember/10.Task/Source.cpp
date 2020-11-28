#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		int product = 1;

		for (int j = i; j <= i + i; j++)
		{
			product *= j;
		}

		sum += product;
	}

	cout << sum << endl;

	return 0;
}