#include <iostream>
#include <string>
using namespace std;
long long process(string str)
{
	int index = str.find(',');
	while (index != string::npos)
	{
		str.erase(index, 1);
		index = str.find(',');
	}
	return atoll(str.c_str());
}
int main()
{
	string num1, num2;
	while (cin >> num1 >> num2)
	{
		long long number1 = process(num1);
		long long number2 = process(num2);
		cout << number1 + number2 << endl;
	}
	return 0;	
}