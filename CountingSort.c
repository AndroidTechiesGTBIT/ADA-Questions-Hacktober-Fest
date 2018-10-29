#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max=0, t, asize;
	scanf("%d",&t);
	asize = t;

	int *a = malloc((asize) * sizeof(int));
	int *b = malloc((asize) * sizeof(int));

	for(int i = 0; i < asize; i++){
		scanf("%d", &a[i]);
		if(max < a[i])
			max = a[i];
	}

	//printf("bp:1\n");
	int *count = malloc((max) * sizeof(int));
	for(int i =0; i <= max; i++)
		count[i] =0;

	//printf("bp:2\n");
	for (int i = 0; i< asize; ++i)
		count[a[i]] = count[a[i]] + 1;

	//printf("bp:3\n");
	for (int i = 1; i <= max; ++i)
	{
		count[i] = count[i] + count[i-1];
	}

	//printf("bp:4\n");
	for(int i = asize-1; i>=0; i--){
		b[count[a[i]] - 1] = a[i];
		--count[a[i]];
	}

	//printf("bp:5\n");
	for (int i = 0; i < asize; ++i)
	{
		printf("%d\n",b[i]);
	}

	free(a);
	free(b);
	free(count);

	printf("\n");
	return 0;
}
