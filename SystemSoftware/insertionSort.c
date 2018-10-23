#include<stdio.h>
void main()
{
	int n,i,j,c=0;
	
	printf("enter thr limit:");
	scanf("%d",&n);
	
	float a[n],t;
	
	printf("enter the array: ");
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
		
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		
		while(t<a[j] && j>=0)
		{
			c++;
		 	a[j+1]=a[j];
		 	j--;
		}
		a[j+1]=t;
	}
	
	
	printf("sorted array: ");
	for(i=0;i<n;i++)
		printf("%f ",a[i]);
	
	printf("\nno of checks=%d",c);
	printf("\n");
}
