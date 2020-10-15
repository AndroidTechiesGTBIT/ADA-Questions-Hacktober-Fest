#include<iostream>
#include<stdlib.h>
#include<process.h>
#include<time.h>
using namespace std;

#define size 100000
void insertionSort(int a[]) {
	int i, j, num;
	for(j=1; j<size; j++) {
		num = a[j];
		i=j-1;
		while(i>=0 && a[i]>num) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = num;
	}
}
int main() {
	int a[size], ch, i;
	cout<<"Insertion Sort\nEnter your Choice:\n1. Best Case\n2. Worst Case\n3. Average Case\n4. Exit\t";
	cin>>ch;
	switch(ch) {
		case 1: for(i=0; i<size; i++) {
					a[i] = i+1;
				}
				break;
		case 2: for(i=size; i>0; i--) {
					a[size-i] = i;
				}
				break;
		case 3: srand(time(NULL));
				for(i=0; i<size; i++) {
					a[i] = rand() % size + 1;
				}
				break;
		case 4: exit(0);
				break;
		default: cout<<"Wrong Choice!\n";
				 break;
	}
	clock_t start, end;
	start = clock();
	insertionSort(a);
	end = clock();
	cout<<"Time Taken: "<<(double)(end-start)/CLK_TCK;
}
