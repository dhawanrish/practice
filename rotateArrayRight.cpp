#include <iostream>
using namespace std;

void swap(int a[], int start, int end)
{
	int temp;
	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;

		start++;
		end--;
	}
}

void RotateK(int a[], int n, int k)
{
	swap(a, 0, n - k - 1);
	swap(a, n - k, n - 1);
	swap(a, 0, n - 1);
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	RotateK(a, 9, 3);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << " ";
	}
}
