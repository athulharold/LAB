#include<stdio.h>
void schedule()
{
	int a[20],n,i,j,count=0;
	printf("\nEnter the number of elements in the disk queue: ");
	scanf("%d",&n);
	printf("\nEnter the disk queue of cylinder numbers: ");

	//INPUTING THE DISK QUEUE
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//INPUTING THE INITIAL HEAD POSITION
	printf("\nEnter the initial head position: ");
	scanf("%d",&pos);
	
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	    if((a[i]-pos)<0)
	    	count+=(a[i]-pos)*-1;
	    else
	    	count+=a[i]-pos;
	    pos=a[i];
	}
	
	printf("\n%d",count);
}	    		
	
	
		
