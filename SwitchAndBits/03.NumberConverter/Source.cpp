# include <iostream>

using namespace std;

int main()
{
	int number = 0;
	cin >> number;

	if (number > 50)
	{
		cout << "L";
		number -= 50;
	}
	else if (number >= 40)
	{
		cout << "XL";
		number -= 40;
	}

	switch (number / 10)
	{
	case 1:
		cout << "X";
		break;
	case 2:
		cout << "XX";
		break;
	case 3:
		cout << "XXX";
		break;
	}

	switch (number % 10)
	{
	case 1:
		cout << "I";
		break;
	case 2:
		cout << "II";
		break;
	case 3:
		cout << "III";
		break;
	case 4:
		cout << "IV";
		break;
	case 5:
		cout << "V";
		break;
	case 6:
		cout << "VI";
		break;
	case 7:
		cout << "VII";
		break;
	case 8:
		cout << "VIII";
		break;
	case 9:
		cout << "IX";
		break;
	}

	cout << endl;

	return 0;
}