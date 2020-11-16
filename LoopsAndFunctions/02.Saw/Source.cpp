#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n <= 2)
	{
		cout << "yes" << endl;
	}
	else
	{
		int left, mid, right;
		cin >> left >> mid;
		bool isValid = true;

		for (int i = 2; i < n; i++)
		{
			cin >> right;

			if (mid > left && mid < right || mid < left && mid > right)
			{
				isValid = false;
				break;
			}

			left = mid;
			mid = right;
		}

		isValid
			? cout << "yes" << endl
			: cout << "no" << endl;
	}

	return 0;
}