#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int min;
	cin >> min;
	int max = min;

	for (int i = 1; i < n; i++)
	{
		int number;
		cin >> number;

		if (max < number)
		{
			max = number;
		}

		if (min > number)
		{
			min = number;
		}
	}

	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;

	return 0;
}