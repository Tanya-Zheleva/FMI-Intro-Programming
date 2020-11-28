#include <iostream>

using namespace std;

int getDigitSum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int getDigitProduct(int n)
{
	int product = 1;

	while (n > 0)
	{
		product *= (n % 10);
		n /= 10;
	}

	return product;
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	int counter = 0;

	for (int i = a; i < b; i++)
	{
		int sum = getDigitSum(i);
		int product = getDigitProduct(i);

		if (sum == product)
		{
			counter++;
		}
	}

	cout << counter << endl;

	return 0;
}