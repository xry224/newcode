#include <iostream>
using namespace std;
int partition(int n, int m)
{
	if(n<1||m<1) return 0;
		
	if(m==1||n==1) return 1;
		
	if(m>n) return partition(n,n);
	
	if(m==n) return partition(n,m-1)+1;
		
	return partition(n,m-1)+partition(n-m,m);
}
int main()
{
	int n,m;
	while (true)
	{
		cin>>n>>m;
		cout <<partition(n,m);
	}


	return 0;
}