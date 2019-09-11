#include <iostream>
using namespace std;

unsigned long long int FindDigits(unsigned int temp)
{
	unsigned long long int c = 1;
	while (temp /= 10)
	{
		c++;
	}
	return c;
}
unsigned long long int Combine(unsigned int temp1, unsigned int temp2)
{
	return temp1*pow(10,FindDigits(temp2)) + temp2;
}
int Partition(int a[], int start, int end)
{
	int pIndex = start, pivot = a[end], temp;
	for (int i = start; i < end; i++)
	{
		if (a[i] > pivot)
		{
			temp = a[i];
			a[i] = a[pIndex];
			a[pIndex] = temp;
			pIndex++;
		}
	}
	temp = a[pIndex];
	a[pIndex] = a[end];
	a[end] = temp;
	return pIndex;
}
void QuickSort(int a[], int start, int end)
{
	if (start < end)
	{
		int pIndex = Partition(a, start, end);
		QuickSort(a, start, pIndex - 1);
		QuickSort(a, pIndex + 1, end);
	}
}
void FindMaxCombination(int a[], int n)
{
	QuickSort(a, 0, n-1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	unsigned long long int temp = a[0];
	for (int i = 1; i < n; i++)
	{
		temp = Combine(temp, a[i])>Combine(a[i], temp) ? Combine(temp, a[i]): Combine(a[i], temp);

	}
	cout << temp;
}
int main()
{
	int a[] = {  91, 999, 89,8,9 };
	//FindMaxCombination(a, 10);
	
	/*for (int i = 0; i < 10; i++)
		cout << a[i] << " ";*/
	FindMaxCombination(a, 5);
