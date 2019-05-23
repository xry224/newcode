#include <iostream>
using namespace std;
long long stair[91] = { 0 };
int S(int n)
{
	if (stair[n] != 0)
	{
		return stair[n];
	}
	stair[n] = S(n - 1) + S(n - 2);
	return stair[n];
}
int main()
{
	stair[1] = 1;
	stair[2] = 2;
	int n;
	S(90);
	while (cin >> n)
	{
		cout << stair[n] << endl;
	}
	return 0;
}