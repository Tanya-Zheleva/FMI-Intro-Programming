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

int getPower(int x, int y)
{
	int result = 1;

	for (int i = 0; i < y; i++)
	{
		result = result * x;
	}

	return result;
}

int main()
{
	int m, n, k;

	do
	{
		cin >> m >> n >> k;

		if (m >= n)
		{
			cout << "N should be > than m" << endl;
		}
		else if (k < 1)
		{
			cout << "K should be > 1" << endl;
		}
	} while (m >= n);

	for (int i = m; i <= n; i++)
	{
		int digitsCount = getDigitsCount(i);

		if (k <= digitsCount)
		{
			int newNumber = 0;
			int power = getPower(10, k - 1);

			newNumber = i / (power * 10) * power + i % power;

			if (newNumber != 0 && i % newNumber == 0)
			{
				cout << i << " ";
			}
		}
	}

	cout << endl;

	return 0;
}