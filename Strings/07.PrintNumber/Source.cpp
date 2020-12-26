#include <iostream>
#include <string.h>

using namespace std;

long long convertToNumber(int* arr)
{
	long long result = 0;
	int power = 0;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				result += i * pow(10, power);
				power++;
			}
		}
	}

	return result;
}

long long getBiggestNumber(char* s)
{
	int digits[10] = {};
	int length = strlen(s);

	for (int i = 0; i < length; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int digit = s[i] - '0';
			digits[digit]++;
		}
	}

	return convertToNumber(digits);
}

int main()
{
	char str[100];
	cin.getline(str, 100);

	cout << getBiggestNumber(str) << endl;

	return 0;
}