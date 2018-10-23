#include<stdio.h>

void fcfs(int wait[],int burst[],int n)
{
	float avw,avt,sumw,sumt;
	int turn[10],i;
	wait[0]=0;	
	turn[0]=burst[0];
	for(i=1;i<n;i++){
		wait[i]=wait[i-1]+burst[i-1];
 		turn[i]=wait[i]+burst[i];
 		printf("\n %d",wait[i]); }
	
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

void sjf()
{
	int burst[10],n,wait[10],i,j,temp;
	printf("\nEnter the number of processes");
	scanf("%d",&n);
	printf("\nEnter the burst time of the processes: ");
	for(i=0;i<n;i++){
		scanf("%d",&burst[i]);}
	for(i=0;i<n;i++){
		for(j=0;j< n-1-i;j++){
			if(burst[j]>burst[j+1]){
				temp=burst[j];
				burst[j]=burst[j+1];
				burst[j+1]=temp;}
					}
		}
	fcfs(wait,burst,n);				
}



void main()
{
	sjf();
}				
