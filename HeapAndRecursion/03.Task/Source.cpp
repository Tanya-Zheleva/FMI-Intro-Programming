#include <iostream>

using namespace std;

bool containsNumber(int* arr, int n, int k)
{
	if (n == 1)
	{
		return arr[0] == k;
	}

	if (arr[n - 1] == k)
	{
		return true;
	}

	return containsNumber(arr, n - 1, k);
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << boolalpha << containsNumber(arr, n, k);

	delete[] arr;

    return 0;
}
