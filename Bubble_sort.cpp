# BUBBLE_SORT

// C++ program for implementation of Bubble sort 
#include <bits/stdc++.h> 
using namespace std;

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 
 
int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]); 
	bubbleSort(arr, n); 
	cout<<"Sorted array: \n"; 
	for(int i=0;i<n;i++) cout<<arr[i]<<" "; 
	return 0; 
}  
