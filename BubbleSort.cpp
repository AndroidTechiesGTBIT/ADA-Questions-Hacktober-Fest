#include<iostream>
using namespace std;
 
int main()
{
	int arr[50],n,i,j,temp;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the array elements: "; 
	for(i=0;i<n;++i)
		cin>>arr[i];
		
	for(i=1;i<n;++i)
	{
		for(j=0;j<(n-i);++j)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	}
	
	cout<<"Array after bubble sort:";
	for(i=0;i<n;++i)
		cout<<" "<<arr[i];
		
	return 0;
}
