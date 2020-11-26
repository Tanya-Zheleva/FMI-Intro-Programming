#include <iostream>

using namespace std;

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int arr[101] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int sum = arr[i], end = 1;

		for (int j = i + 1; j < n; j++)
		{
			if (sum >= k)
			{
				break;
			}

			sum += arr[j];
			end = j;
		}

		if (sum == k)
		{
			cout << i << " " << end << endl;
		}
	}

	return 0;
}