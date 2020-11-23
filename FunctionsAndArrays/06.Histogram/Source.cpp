#include <iostream>

using namespace std;

int main()
{
	long long n = 0;
	cin >> n;
	int digits[10] = {};

	if (n == 0)
	{
		digits[0] = 1;
	}

	while (n > 0)
	{
		int lastDigit = n % 10;
		digits[lastDigit]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << i << "-" << digits[i] << endl;
	}

	return 0;
}