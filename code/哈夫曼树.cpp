#include <iostream>
#include <queue> 
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> >Q;    //Ð¡¶¥¶Ñ
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			Q.push(t);
		}
		int ans = 0;
		while (Q.size() > 1)
		{
			int t1 = Q.top();
			Q.pop();
			int t2 = Q.top();
			Q.pop();

			int t3 = t1 + t2;
			ans += t3;
			Q.push(t3);
		}
		cout << ans << endl;
	}
	return 0;
}