#include <iostream>
#include<string>
#include <stack>
#include <iomanip>
using namespace std;
bool isOp(char str)
{
	if (str == '+' || str == '-' || str == '*' || str == '/')
	{
		return true;
	}
	return false;
}
//检测第一个操作符是否大于运算优先级是否大于第二个运算符
bool cmpOP(char op1, char op2)
{
	if (op1 == '/' || op1 == '*')
	{
		if (op2 == '+' || op2 == '-')
		{
			return true;
		}
	}
	return false;
}
bool equalOP(char op1, char op2)
{
	if (op1 == '/' || op1 == '*')
	{
		if (op2 == '/' || op2 == '*')
		{
			return true;
		}
	}
	if (op1 == '-' || op1 == '+')
	{
		if (op2 == '-' || op2 == '+')
		{
			return true;
		}
	}
	return false;
}
double Cal(char op, double n1, double n2)
{
	switch (op)
	{
	case '+':
	{
		return n1 + n2;
		break;
	}
	case '-':
	{
		return n1 - n2;
		break;
	}
	case '*':
	{
		return n1 * n2;
		break;
	}
	case '/':
	{
		return n1 / n2;
		break;
	}
	}
	return -1;
}
string getNum(string content, int index)
{
	string ans = "";
	for (int i = index; i < content.length(); i++)
	{
		if (!isOp(content[i]))
		{
			ans += content[i];
		}
	}
	return ans;
}
int main()
{
	string content;
	while (getline(cin, content))
	{
		if (content == "0")
		{
			break;
		}
		stack<char> op;
		stack<double> num;
		for (int i = 0; i < content.length(); i++)
		{
			//空格直接略过
			if (content[i] == ' ')
			{
				continue;
			}
			//不是运算符，数字直接入栈
			if (!isOp(content[i]))		
			{
				string subnum = "";
				for (int j = i; j < content.length(); j++)
				{
					if (!isOp(content[j]))
					{
						subnum += content[j];
						if (j == content.length() - 1)
						{
							i = j;
							break;
						}
					}
					else
					{
						i = j - 1;
						break;
					}
				}
				
				double number = atof(subnum.c_str());
				num.push(number);
				continue;
			}
			//是运算符的情况
			//运算符栈为空
			if (op.empty())
			{
				op.push(content[i]);
			}
			else
			{
				char op1 = op.top();
				//栈顶运算符优先级大于或等于当前的运算符时
				while ((cmpOP(op1, content[i]) || equalOP(op1, content[i])) && !op.empty() && !num.empty())
				{
					
					//取出数字栈顶两个元素
					double n1 = num.top();
					num.pop();
					double n2 = num.top();
					num.pop();
					double ans = Cal(op1, n2, n1);
					num.push(ans);//结果入栈						
					//cout << n2<<" "<<n1<<" "<<op1<<" "<<ans << endl;
					op.pop();
					if (!op.empty())
					{
						op1 = op.top();
					}
				}
				op.push(content[i]);
			}

		}
		//计算剩余的+运算与-运算
		while (!op.empty() && !num.empty())
		{
			char op1 = op.top();
			//取出数字栈顶两个元素
			double n1 = num.top();
			num.pop();
			double n2 = num.top();
			num.pop();
			double ans = Cal(op1, n2, n1);
			num.push(ans);//结果入栈
			op.pop();
		}
		double ans = num.top();
		num.pop();
		cout << fixed << setprecision(0) << ans << endl;
	}
	return 0;
}