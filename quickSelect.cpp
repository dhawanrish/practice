#include <iostream>
using namespace std;

int partition(int *A, int start, int end){
	int pivot = A[end], pIndex = start, x, temp;

	for (x = start; x < end; x++){
		if (A[x] <= pivot){
			temp = A[pIndex];
			A[pIndex] = A[x];
			A[x] = temp;
			pIndex++;
		}
	}

	temp = A[pIndex]; A[pIndex] = A[end]; A[end] = temp;
	return pIndex;
}


int quickselect(int *A, int left, int right, int k){

	//p is position of pivot in the partitioned array
	int p = partition(A, left, right);

	//k equals pivot got lucky
	if (p == k - 1){
		return A[p];
	}
	//k less than pivot
	else if (k - 1 < p){
		return quickselect(A, left, p - 1, k);
	}
	//k greater than pivot
	else{
		return quickselect(A, p + 1, right, k);
	}
}

int main()
{
	int arr[] = {4,1,9,7,8,5,2,6,3};
	int n = 9;

	/*cin >> n;
	arr = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}*/

	cout << quickselect(arr, 0, n-1, 1);
	cout << quickselect(arr, 0, n - 1, 2);
	cout << quickselect(arr, 0, n - 1, 3);
}
