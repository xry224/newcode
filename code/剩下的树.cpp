#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int L, M;
	
	while (cin >> L >> M)
	{
		char Seg[10001];
		memset(Seg, 1, sizeof(Seg));
		for (int i = 0; i < M; i++)
		{
			int left, right;
			cin >> left >> right;
			memset(&Seg[left], 0, right - left + 1);

		}
		int cnt = 0;
		for (int i = 0; i <= L; i++)
		{
			if (Seg[i] == 1)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
