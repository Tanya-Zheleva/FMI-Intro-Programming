#include <iostream>

using namespace std;

int getMostCommonNameIndex(char names[][100], int n, int& timesFound)
{
	int mostCommonIndex = 0, maxTimesFound = 0;

	for (int i = 0; i < n; i++)
	{
		int found = 1;

		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(names[i], names[j]) == 0)
			{
				found++;
			}
		}

		if (found > maxTimesFound)
		{
			maxTimesFound = found;
			mostCommonIndex = i;
		}
	}

	timesFound = maxTimesFound;

	return mostCommonIndex;
}

int main()
{
	int n = 0;
	cin >> n;
	char strings[50][100];

	for (int i = 0; i < n; i++)
	{
		cin >> strings[i];
	}

	int maxTimesFoundName = 0;
	int maxNameIndex = getMostCommonNameIndex(strings, n, maxTimesFoundName);

	cout << strings[maxNameIndex] << "  " << maxTimesFoundName << endl;

	return 0;
}