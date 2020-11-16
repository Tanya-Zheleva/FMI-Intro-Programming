#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int i = 2;
	bool skipDot = true;

	while (i < n)
	{
		if (n % i == 0)
		{
			if (!skipDot)
			{
				cout << ".";
			}

			cout << i;
			skipDot = false;
			n /= i;

			if (n == 1)
			{
				break;
			}
		}
		else
		{
			i++;
		}
	}

	if (skipDot)
	{
		cout << n << endl;
	}
	else if (n != 1)
	{
		cout << "." << n << endl;
	}

	return 0;
}