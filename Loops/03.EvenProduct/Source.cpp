#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	double product = 1;

	for (int i = 1; i <= n; i++)
	{
		double current;
		cin >> current;

		if (i % 2 == 0)
		{
			product *= current;
		}
	}

	cout << product << endl;

	return 0;
}