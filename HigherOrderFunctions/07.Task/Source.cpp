#include <iostream>
#include <cstring>

typedef int(*func)(int, int);

int getPoweMod(int a, int b)
{
	return (a * a + b * b) % 10;
}

int getSumMod(int a, int b)
{
	return (3 * a + 4 * b) % 10;
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int getValue(char* str, int startPos, int endPos, func f, func g)
{
	if (startPos == endPos)
	{
		return str[startPos] - '0';
	}

	int x, y;
	char funcName = str[startPos];
	startPos += 2;

	if (isDigit(str[startPos]))
	{
		x = str[startPos] - '0';
	}
	else
	{
		int numBraces = 1, pos = startPos + 2; //first brace is counted, we need to find its closing one

		while (numBraces != 0)
		{
			pos++;

			if (str[pos] == '(')
			{
				numBraces++;
			}

			if (str[pos] == ')')
			{
				numBraces--;
			}
		}

		x = getValue(str, startPos, pos, f, g);
	}

	endPos--;

	if (isDigit(str[endPos]))
	{
		y = str[endPos] - '0';
	}
	else
	{
		int numBraces = -1, pos = endPos; //the last brace not is counted, we need one more opening

		while (numBraces != 0)
		{
			pos--;

			if (str[pos] == '(')
			{
				numBraces++;
			}

			if (str[pos] == ')')
			{
				numBraces--;
			}
		}

		y = getValue(str, pos - 1, endPos, f, g);
	}

	if (funcName == 'f')
	{
		return f(x, y);
	}

	return g(x, y);
}

int main()
{


    return 0;
}