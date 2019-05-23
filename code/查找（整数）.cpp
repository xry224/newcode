#include <iostream>
using namespace std;
void quicksort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = a[left];
	int first = left;
	int last = right;
	while (first < last)
	{
		while (first < last && a[last] >= key)
		{
			last--;
		}
		a[first] = a[last];
		while (first < last && a[first] <= key)
		{
			first++;
		}
		a[last] = a[first];
	}
	a[first] = key;
	quicksort(a, left, first - 1);
	quicksort(a, first + 1, right);
}
int BinarySearch(int a[], int len, int target)
{
	int left = 0, right = len - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == target)
		{
			return mid;
		}
		else if (a[mid] > target)
		{
			right = mid - 1;
		}
		else if (a[mid] < target)
		{
			left = mid + 1;
		}
	}
	return -1;
}
int main()
{		
	int n, m;
	while (cin >> n)
	{

		int num[100], sear[100];
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> sear[i];
		}

		quicksort(num, 0, n - 1);
		for (int i = 0; i < m; i++)
		{
			if (BinarySearch(num, n, sear[i]) != -1)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}