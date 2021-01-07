#include <iostream>

using namespace std;

bool isPalindrome(int number, int factor) {
	if (number / 10 > 0)
	{
		int firstPart = number / factor;
		int secondPart = number % 10;

		if (firstPart == secondPart)
		{
			number %= factor;

			return isPalindrome(number / 10, factor / 100);
		}

		return false;
	}

	return true;
}

int main()
{
	int n = 0;
	cin >> n;

	int power = 1, temp = n;

	while (temp > 9)
	{
		power *= 10;
		temp /= 10;
	}

	cout << boolalpha << isPalindrome(n, power) << endl;

	return 0;
}