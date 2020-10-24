#include<iostream>
#include<stdlib.h>
#include<process.h>
#include<time.h>
using namespace std;
void merge(int a[], int p, int q, int r)
{
	int nl = q-p+1, nr = r-q, i, j, k;
	int *L = new int[nl], *R = new int[nr];
	for(i=0; i<=nl; i++) {
		L[i] = a[p+i-1];
		cout<<i;
	}
	for(j=0; j<=nr; j++) {
		R[j] = a[q+j];
	}
	i=j=k=0;
	while(i<nl && j<nr)
	{
		if(L[i]<R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		a[k]=R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}
void mergeSort(int a[], int p, int r)
{
	int q;
	if(p < r) {
		q = (p+r)/2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	}
}

int main() {
	int a[1000], size=1000, ch, i;
	cout<<"Merge Sort\nEnter your Choice:\n1. Best Case\n2. Worst Case\n3. Average Case\n4. Exit\t";
	cin>>ch;
	switch(ch) {
		case 1: for(i=0; i<1000; i++) {
					a[i] = i+1;
				}
				break;
		case 2: for(i=1000; i>0; i--) {
					a[1000-i] = i;
				}
				break;
		case 3: srand(time(NULL));
				for(i=0; i<1000; i++) {
					a[i] = rand() % 1000 + 1;
				}
				break;
		case 4: exit(0);
				break;
		default: cout<<"Wrong Choice!";
				 break;
	}
	clock_t start, end;
	start = clock();
	mergeSort(a, 0, size-1);
	end = clock();
	cout<<"Time Taken: "<<(double)(end-start)/CLK_TCK;
}
