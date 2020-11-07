#include <iostream>

using namespace std;

int main()
{
	int x, n;
	cin >> x >> n;
	long long result = 1;

	for (int i = 0; i < n; i++)
	{
		result = result * x;
	}

	cout << result << endl;

	return 0;
}