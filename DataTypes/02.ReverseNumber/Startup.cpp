#include <iostream>

using namespace std;

int main()
{
	int number = 0;
	cin >> number;

	int firstDigit = number % 10;
	number /= 10;

	int secondDigit = number % 10;
	number /= 10;

	int thirdDigit = number % 10;
	number /= 10;

	int lastDigit = number;
	int reversedNumber = firstDigit * 1000 + secondDigit * 100 + thirdDigit * 10 + lastDigit;

	cout << reversedNumber << endl;

	return 0;
}