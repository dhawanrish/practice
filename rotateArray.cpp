#include <iostream>
using namespace std;

void FindMinRotArr(int *a, int n)// Avg complexit O(logN) worst O(N)
{
	int low = 0, high = n - 1, mid=0, index = 0;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (a[mid] >a[mid+1])
		{
			index = mid+1;
			break;
		}
		else if (a[mid] > a[high])
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	cout << "Min " << a[index] << endl;
}

void FindMinRotArr2(int *a, int n) // Avg complexit O(logN) worst O(logN)
{
	int low = 0, high = n - 1, mid = 0;

	while (a[low] > a[high])
	{
		mid = (low + high) / 2;
		if (a[mid] > a[high])
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	cout << "Min " << a[low] << endl;
}

int main()
{
	int arr[] = {4,5,6,7,8,9,1,2,3};
	int arr1[] = { 6, 7, 8, 9, 1, 2, 3,4, 5 };
	int arr2[] = { 8, 9, 1, 2, 3,4,5,6,7 };
	int n = 9;

	/*cin >> n;
	arr = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}*/

	FindMinRotArr2(arr, n);
	FindMinRotArr2(arr1, n);
	FindMinRotArr2(arr2, n);
}
