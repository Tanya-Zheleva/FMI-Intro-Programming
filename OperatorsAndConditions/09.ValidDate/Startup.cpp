#include <iostream>

using namespace std;

int main()
{
	int day = 0, month = 0, year = 0;
	cin >> day >> month >> year;

	bool isFebruary = month == 2;
	bool has30Days = month == 4 || month == 6 || month == 9 || month == 11;
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	bool hasInvalidValues = day > 31 || day < 1 || month > 12 || month < 1 || year < 0;
	bool isValidDate = true;

	if (hasInvalidValues || (has30Days && day > 30))
	{
		isValidDate = false;
	}
	else if (isFebruary)
	{
		if (isLeapYear && day > 29 || !isLeapYear && day > 28)
		{
			isValidDate = false;
		}
	}

	if (isValidDate)
	{
		if (isFebruary)
		{
			int lastDay = isLeapYear ? 29 : 28;
			day < lastDay
				? cout << "Next date: " << day + 1 << "/" << month << "/" << year << endl
				: cout << "Next date: " << 1 << "/" << month + 1 << "/" << year << endl;

		}
		else if (has30Days)
		{
			day < 30
				? cout << "Next date: " << day + 1 << "/" << month << "/" << year << endl
				: cout << "Next date: " << 1 << "/" << month + 1 << "/" << year << endl;
		}
		else
		{
			if (day < 31)
			{
				cout << "Next date: " << day + 1 << "/" << month << "/" << year << endl;
			}
			else
			{
				month == 12
					? cout << "Next date: " << 1 << "/" << 1 << "/" << year + 1 << endl
					: cout << "Next date: " << 1 << "/" << month + 1 << "/" << year << endl;
			}
		}
	}
	else 
	{
		cout << "Invalid date" << endl;
	}

	return 0;
}