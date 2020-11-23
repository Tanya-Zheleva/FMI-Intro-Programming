#include <iostream>

using namespace std;

const int SIZE = 100;

void readArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int first[SIZE] = {};
	int second[SIZE] = {};

	readArray(first, n);
	readArray(second, n);

	if (n == 0)
	{
		first[0] == 0 && second[0] == 0
			? cout << "Yes" << endl
			: cout << "No" << endl;

		return 0;
	}

	int coeff = second[0] / first[0];
	bool hasLinearDependance = true;

	for (int i = 1; i < n; i++)
	{
		if (second[i] / first[i] != coeff)
		{
			hasLinearDependance = false;
			break;
		}
	}

	hasLinearDependance
		? cout << "Yes" << endl
		: cout << "No" << endl;

	return 0;
}