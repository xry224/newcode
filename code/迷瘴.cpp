#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, V, w;
		cin >> n >> V >> w;
		int con[102];
		double content[102];
		for (int i = 0 ; i < n ; i++)
		{
			cin >> con[i];
			content[i] = con[i] * V * 0.01;
		}
		sort(content, content + n);
		double curcon = 0;
		int curv = 0;
		for (int i = 0 ; i < n ; i++)
		{
			if ( (double)(curcon + content[i]) / (double)(curv + V) - 0.000001 <= w * 0.01 )
			{
				curcon += content[i];
				curv += V;
				//cout << (curcon + content[i]) / (double)(curv + V) <<endl;
			} 
			else
			{
				break;
			}
		}
		if (curcon != 0)
		cout << curv << " " << fixed << setprecision(2) << (curcon)  / (double)(curv) << endl;
		else
		cout << "0 0.00" << endl;

	}
	//system("pause");
	return 0;
}