#include <iostream>

using namespace std;

int main()
{
	unsigned n;
	cin >> n;
	int flags = 0;

	if (n == 0)
	{
		flags = 1;
	}
	else
	{
		while (n != 0)
		{
			flags = flags | 1 << n % 10;
			n /= 10;
		}	
	}

	for (int i = 0; i < 10; i++)
	{
		if (!(flags & 1 << i))
		{
			cout << i << endl;
		}
	}

	return 0;
}