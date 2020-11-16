#include <iostream>

using namespace std;

long long toAnotherBase(long long x, int fromBase, int toBase)
{
	long long result = 0;
	int power = 1;

	while (x != 0)
	{
		result += (x % toBase) * power;
		x /= toBase;
		power *= fromBase;
	}

	return result;
}

long long decimalToBinary(int x)
{
	return toAnotherBase(x, 10, 2);
}

long long binaryToDecimal(int x)
{
	return toAnotherBase(x, 2, 10);
}

long long transform(long long x)
{
	long long result = 0;
	int power = 1;

	while (x != 0)
	{
		int digit = x % 10;
		int prevDigit = (x / 10) % 10;

		if (digit == prevDigit)
		{
			digit = (digit + 1) % 2;
		}

		result += digit * power;
		x /= 10;
		power *= 10;
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	long long transformedBinary = transform(decimalToBinary(n));
	cout << n << " " << decimalToBinary(n) << " " << transformedBinary << " " << binaryToDecimal(transformedBinary) << endl;

	return 0;
}