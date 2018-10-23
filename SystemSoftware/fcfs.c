#include<stdio.h>
 
void fcfs(){
	
	int burst[10],wait[10],turn[10],n,i;

	float sumw=0,sumt=0,avw,avt;
	printf("\nEnter the total number of processes");
	scanf("%d",&n); 
	printf("\nEnter the burst time of the processes: ");
	for(i=0;i<n;i++){
			scanf("%d",&burst[i]);}
			 
	wait[0]=0;	
	turn[0]=burst[0];
	printf("Waiting time of processes are: ");
	printf("\n %d",wait[0]);
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

void main()
{
	fcfs();
	
}
		
	
	
	
				
				
				
				 
	
	
