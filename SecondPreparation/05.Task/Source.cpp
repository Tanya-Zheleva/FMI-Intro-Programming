#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char str[100];
	cin.getline(str, 100);

	int depth = 0, maxDepth = 0, openIndex = -1, closeIndex = -1;
	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(')
		{
			depth++;

			if (maxDepth < depth)
			{
				maxDepth = depth;
				openIndex = i;
			}
		}

		if (str[i] == ')')
		{
			depth--;
		}
	}

	if (depth != 0)
	{
		cout << "Invalid" << endl;

		return 0;
	}

	cout << openIndex << " ";

	closeIndex = openIndex;

	while (str[closeIndex] != ')')
	{
		closeIndex++;
	}

	cout << closeIndex << endl;

	return 0;
}