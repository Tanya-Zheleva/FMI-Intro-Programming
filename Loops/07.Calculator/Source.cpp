#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;

	double result = number;

	char op;
	cin >> op;

	while (op != '=')
	{
		cin >> number;

		switch (op)
		{
		case '+':
			result += number;
			break;
		case '-':
			result -= number;
			break;
		case '*':
			result *= number;
			break;
		case '/':
			if (number != 0)
			{
				result /= number;
			}
			break;
		}

		cin >> op;
	}

	cout << result << endl;

	return 0;
}