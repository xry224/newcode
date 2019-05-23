#include <iostream>
using namespace std;
#define SIZE 1000000
int check[SIZE] = { 0 };
int prime[SIZE];
int cnt = 0;
void Prime()
{
	for (int i = 2; i < SIZE; i++)
	{
		if (!check[i])
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i*prime[j] < SIZE; j++)
		{
			check[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int main()
{
	int k;
	Prime();
	while (cin >> k)
	{
		cout << prime[k - 1] << endl;
	}
	return 0;
}
