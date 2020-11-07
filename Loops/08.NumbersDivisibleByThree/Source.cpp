#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int numbersFound = 0;

	for (int i = 0; i < n; i++)
	{
		int current;
		cin >> current;

		int temp = current;
		int digitSum = 0;

		while (temp != 0)
		{
			digitSum += temp % 10;
			temp /= 10;
		}

		if (digitSum % 3 == 0)
		{
			cout << current << " ";
			numbersFound++;
		}
	}

	cout << endl << "Total found: " << numbersFound << endl;

	return 0;
}