#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int rev = 0;
	int temp = n;

	do
	{
		int digit = temp % 10;
		rev = rev * 10 + digit;
		temp /= 10;
	} while (temp != 0);

	rev == n
		? cout << "Palindrome"
		: cout << "Not plalindome " << n << " " << rev << endl;

	return 0;
}