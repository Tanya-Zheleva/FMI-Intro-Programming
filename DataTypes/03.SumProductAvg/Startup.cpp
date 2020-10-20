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
	int sum = firstDigit + secondDigit + thirdDigit + lastDigit;
	int product = firstDigit * secondDigit * thirdDigit * lastDigit;
	double average = sum / 4.0;

	cout << "sum = " << sum << " ";
	cout << "p = " << product << " ";
	cout << "avg = " << average << endl;

	return 0;
}