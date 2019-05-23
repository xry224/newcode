#include <iostream>
#include <string>
#include<map>
using namespace std;
map<string, int> convert;
int getNum(string str)
{
	return convert[str];
}
long long process(string str)
{
	long long ans = 0;
	string t = str;
	while (t.length() > 0)
	{
		int index = t.find(' ');
		if (index == string::npos)
		{
			ans *= 10;
			ans += getNum(t);
			break;
		}
		string temp = t.substr(0, index);
		t = t.substr(index + 1);
		//cout << t << endl;
		ans *= 10;
		ans += getNum(temp);
	}
	return ans;
}
void Ini()
{
	string t = "zero";
	convert[t] = 0;
    t = "one";
	convert[t] = 1;
	t = "two";
	convert[t] = 2;
	t = "three";
	convert[t] = 3;
	t = "four";
	convert[t] = 4;
	t = "five";
	convert[t] = 5;
	t = "six";
	convert[t] = 6;
	t = "seven";
	convert[t] = 7;
	t = "eight";
	convert[t] = 8;
	t = "nine";
	convert[t] = 9;
}
int main()
{
	string num1, num2;
	string str;
	Ini();
	while (getline(cin, str))
	{
		int indexadd = str.find('+');
		int indexequal = str.find('=');
		num1 = str.substr(0, indexadd - 1);
		num2 = str.substr(indexadd + 2, indexequal - indexadd - 3);
		if (num1 == "zero" && num2 == "zero")
		{
			break;
		}
		long long n1 = process(num1);
		long long n2 = process(num2);
		cout << n1 + n2 << endl;
	}
	return 0;
}