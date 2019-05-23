#include <iostream>
using namespace std;
void qsort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int first = left;
	int last = right;
	int key = a[first];
	while (first < last)
	{
		while (first < last && key <= a[last])
		{
			last--;
		}
		a[first] = a[last];
		while (first < last && key >= a[first])
		{
			first++;
		}
		a[last] = a[first];
	}
	a[first] = key;
	qsort(a, left, first - 1);
	qsort(a, first + 1, right);
}
int main()
{
	int n;
	int arr[1000];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		if (n == 1)
		{
			cout << arr[0] << endl;
			cout << -1 << endl;
			continue;
		}
		qsort(arr, 0, n - 1);
		cout << arr[n - 1] << endl;
		for (int i = 0; i < n - 2; i++)
		{
			cout << arr[i] << " ";
		}
		cout << arr[n - 2] << endl;
		

	}

}