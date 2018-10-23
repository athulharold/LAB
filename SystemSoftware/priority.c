#include<stdio.h>

void fcfs(int wait[],int burst[],int n)
{
	float avw,avt,sumw=0,sumt=0;
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

void priority()
{
	int burst[10],priority[10],wait[10],i,j,n,temp1,temp2;
	printf("\nEnter the total number of processes");
	scanf("%d",&n); 
	printf("\nEnter the burst time of the processes: ");
	for(i=0;i<n;i++){
			scanf("%d",&burst[i]);}
	printf("Enter the priority of the processes: ");		
		for(i=0;i<n;i++)
			scanf("%d",&priority[i]);
	for(i=0;i<n;i++){
		for(j=0;j< n-1-i;j++){
			if(priority[j]>priority[j+1]){
				temp1=priority[j];
				temp2=burst[j];
				priority[j]=priority[j+1];
				burst[j]=burst[j+1];
				priority[j+1]=temp1;
				burst[j+1]=temp2;}
					}
		}		
		
	fcfs(wait,burst,n);
}

void main()
{
	priority();
}	
		
