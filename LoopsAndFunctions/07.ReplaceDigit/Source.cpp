#include <iostream>

using namespace std;

int getDigitsCount(int n)
{
	int digits = 0;

	while (n != 0)
	{
		digits++;
		n /= 10;
	}

	return digits;
}

int main()
{
	int n, oldDigit, newDigit;
	cin >> n >> oldDigit >> newDigit;

	int digits = getDigitsCount(n);
	int k = 1;

	for (int i = 1; i <= digits; i++)
	{
		if ((n / k) % 10 == oldDigit)
		{
			n = (n / (k * 10) * 10 + newDigit) * k + n % k;
		}

		k *= 10;
	}

	cout << n << endl;

	return 0;
}