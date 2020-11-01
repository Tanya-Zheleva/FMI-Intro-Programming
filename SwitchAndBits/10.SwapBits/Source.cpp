# include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int c = n ^ m;
	int count = 0;

	while (c > 0)
	{
		if (c & 1)
		{
			count++;
		}

		c >>= 1;
	}

	cout << count << endl;

	return 0;
}