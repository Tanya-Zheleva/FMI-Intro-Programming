#include <iostream>

using namespace std;

const int SIZE = 100;

void readArray(char sequence[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
}

bool isPalindrome(char sequence[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		if (sequence[i] != sequence[n - i - 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	char sequence[SIZE] = {};

	readArray(sequence, n);

	isPalindrome(sequence, n)
		? cout << "Yes" << endl
		: cout << "No" << endl;

	return 0;
}