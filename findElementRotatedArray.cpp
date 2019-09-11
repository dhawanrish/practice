#include <iostream>
using namespace std;

int BinSearch(int a[], int start, int end, int val)
{
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (a[mid] == val)
		{
			return mid;
		}
		if (a[mid] < val)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	return -1;
}
void ModBinarySearch(int a[], int n, int val)
{
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;
	int i;
	while (a[mid] < a[mid + 1])
	{
		if (a[mid] < a[low])
		{
			high = mid; 
		}
		else
		{
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	if ((i = BinSearch(a, 0, mid, val)) > 0)
		cout << i;
	else
		cout << BinSearch(a, mid + 1, n - 1, val);
}
int main()
{
	int a[] = { 4, 5, 6, 7, 8, 9, 1,2,3 };
	ModBinarySearch(a, 9, 1);
