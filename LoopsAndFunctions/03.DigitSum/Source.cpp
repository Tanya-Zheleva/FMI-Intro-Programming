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
	int n;
	cin >> n;

	int digits = getDigitsCount(n);
	
	if (digits % 2 == 0)
	{
		int start = getPower(10, digits - 1);
		int end = n, startSum = 0, endSum = 0;

		for (int i = 0; i < digits / 2; i++)
		{
			startSum += (n / start) % 10;
			endSum += end % 10;

			start /= 10;
			end /= 10;
		}

		startSum == endSum 
			? cout <<"Equal" << endl 
			: cout << "Different " << startSum << " " << endSum << endl;
	}
	else
	{
		cout << "Invalid number" << endl;
	}

	return 0;
}