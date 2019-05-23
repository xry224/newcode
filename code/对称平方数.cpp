#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
bool check(int num)
{
	int sq = num * num;
	string str = to_string(sq);
	for (int i = 0, j = str.length() - 1; i < j; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	for (int i = 0; i < 256; i++)
	{
		if (check(i))
		{
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}