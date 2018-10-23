#include<stdio.h>

void swap(float *a,float *b)
{
	float t;
	t=*a;
	*a=*b;
	*b=t;
}

int partition(float a[],int p,int r)
{
	float pivot=a[r];
	int i=p,j;
	
	for(j=p;j<r;j++)
	{
		if(a[j]<=pivot)
		{
			swap(&a[j],&a[i]);
			i++;
		}
	}
	swap(&a[i],&a[r]);
	return i;
}

void quickSort(float a[],int p,int r)
{
	int pi;
	if(p<r)
	{
		pi=partition(a,p,r);
		
		quickSort(a,p,pi-1);
		quickSort(a,pi+1,r);
	}
}

void main()
{
	int n,i;
	
	printf("enter thr limit:");
	scanf("%d",&n);
	
	float a[n];
	
	printf("enter the array: ");
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
	
	quickSort(a,0,n-1);
	
	printf("sorted array: ");
	for(i=0;i<n;i++)
		printf("%f ",a[i]);
	
	printf("\n");
}
