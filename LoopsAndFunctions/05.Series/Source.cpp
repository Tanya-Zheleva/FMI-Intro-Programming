#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		int temp = i;
		bool isValid = true;

		int digit = temp % 10;
		temp /= 10;

		while (temp != 0)
		{
			int currentDigit = temp % 10;

			if (currentDigit > digit)
			{
				isValid = false;
				break;
			}

			digit = currentDigit;
			temp /= 10;
		}

		if (isValid)
		{
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}