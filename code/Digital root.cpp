#include <iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		int root = 0;
		int t = num;
		do
		{
			root = 0;
			while (t > 0)
			{
				root += t % 10;
				t = t / 10;
			}
			t = root;
		} while (t >= 10);
		cout << root << endl;
	}
	return 0;
}