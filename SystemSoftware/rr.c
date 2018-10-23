#include<stdio.h>

void rr()
{
	int burst[10],wait[10],turn[10],n,i,remburst[10],quantum,t=0,flag=0,count=0;
	float sumw=0,sumt=0,avw,avt;
	printf("\nEnter the total number of processes");
	scanf("%d",&n); 
	printf("\nEnter the burst time of the processes: ");
	for(i=0;i<n;i++){
			scanf("%d",&burst[i]);}
	
	printf("\nEnter the time quantum of the round robin scheduling: ");
	scanf("%d",&quantum);
	for(i=0;i<n;i++){
		remburst[i]=burst[i];}
	
	while(flag==0)
	{
		
		for(i=0;i<n;i++)
			{
				if(remburst[i]!=0)
				{
					if(remburst[i] > quantum){
						t=t+quantum;
						remburst[i]-= quantum;
						}
					else{
						t=t+remburst[i];
						wait[i]=t-burst[i];
						remburst[i]=0;
						}
				}
			}
		count=0;	
		for(i=0;i<n;i++){
			if(remburst[i]==0)
				count++;}
		if(count==n)
			flag=1;
		else
		 flag=0;	

				
	}

	
	for(i=0;i<n;i++)
		turn[i]=wait[i]+burst[i];
		
	for(i=0;i<n;i++){
		printf("\n wait %d ", wait[i]);
		printf("\n turn %d", turn[i]);
		}
	for(i=0;i<n;i++)
	{
		sumw+= wait[i];
		sumt+= turn[i];	
	}
	avw= sumw/n;
	avt= sumt/n;
	printf("\nThe average waiting time of the processes is %f", avw);
	printf("\nThe average tunaround time of the processes is %f", avt);
}

void main()
{
	rr();
}		
	
								
		
	
