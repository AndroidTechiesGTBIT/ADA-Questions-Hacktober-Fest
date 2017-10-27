#include<iostream>
#include<stdlib.h>
#include<process.h>
#include<time.h>
using namespace std;
int partition(int a[], int beg, int end)
{
	int pivot = a[end], pivot_index = beg, i, temp;
	for(i=beg; i<end; i++)
	{
		if(a[i]<=pivot)
		{
			temp = a[i];
			a[i] = a[pivot_index];
			a[pivot_index] = temp;
			pivot_index++;
		}
	}
	temp = a[end];
	a[end] = a[pivot_index];
	a[pivot_index] = temp;
	return pivot_index;
}
void quickSort(int a[], int beg, int end) {
	if(beg<end) {
		int pos = partition(a,beg,end);
		quickSort(a,beg,pos-1);
		quickSort(a,pos+1,end);
	}
}

int main() {
	int a[10000], size=10000, ch, i;
	cout<<"Quick Sort\nEnter your Choice:\n1. Best Case\n2. Worst Case\n3. Average Case\n4. Exit\t";
	cin>>ch;
	switch(ch) {
		case 1: for(i=0; i<10000; i++) {
					a[i] = i+1;
				}
				break;
		case 2: for(i=10000; i>0; i--) {
					a[10000-i] = i;
				}
				break;
		case 3: srand(time(NULL));
				for(i=0; i<10000; i++) {
					a[i] = rand() % 10000 + 1;
				}
				break;
		case 4: exit(0);
				break;
		default: cout<<"Wrong Choice!";
				 break;
	}
	clock_t start, end;
	start = clock();
	quickSort(a, 0, size-1);
	end = clock();
	cout<<"Time Taken: "<<(double)(end-start)/CLK_TCK;
}
