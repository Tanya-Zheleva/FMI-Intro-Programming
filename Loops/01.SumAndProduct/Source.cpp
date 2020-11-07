#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	long product = 1;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;

		sum += number;
		product *= number;
	}

	cout << sum << endl;
	cout << product << endl;

	return 0;
}