#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		char op;
		stack<int> num;
		for (int i = 0; i < n; i++)
		{
			cin >> op;
			switch (op)
			{
			case 'A':
			{
				if (num.empty())
				{
					cout << 'E' << endl;
				}
				else
				{
					cout << num.top() << endl;
				}
				break;
			}
			case 'O':
			{
				if (!num.empty())
				{
					num.pop();
				}
				break;
			}
			case 'P':
			{
				int val;
				cin >> val;
				num.push(val);
				break;
			}
			default:
			{
				break;
			}
			}
		}
		cout << endl;
	}
	return 0;
}