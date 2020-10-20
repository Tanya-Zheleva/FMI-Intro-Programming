#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	double a = 0, b = 1;
	cin >> a >> b;

	double result = a / b;

	cout << fixed << setprecision(7) << result << endl;

	//fixed reference: http://www.cplusplus.com/reference/ios/fixed/
	//setprecision reference: http://www.cplusplus.com/reference/iomanip/setprecision/

	return 0;
}