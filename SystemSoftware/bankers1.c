#include<stdio.h>
#include<stdlib.h>
void bankers()
{
	int allocation[10][10],finish[10],available[10],max[10][10],need[10][10],pno,rno,i,j,k,count,flag=0,countr,flagcount=0;
	
	printf("\nEnter the number of resources :");
	scanf("%d",&rno);
	
	printf("\nEnter the number of processes :");
	scanf("%d",&pno);
	
	//ENTERING VALUES INTO MATRIX AVAILABLE
	printf("\nEnter the number of available resources for each resource respectively:");
	for(i=0;i<rno;i++)
	{
		scanf("%d",&available[i]);
	}	
	
	//PRINTING AVAILABLE
	printf("\nAvailable: ");
	for(i=0;i<rno;i++)
	{
		printf("%d",available[i]);
	}	
		
	
	//ENTERING VALUES INTO MATRIX MAX
	
	printf("\nEnter the maximum number of resources that could be allocated to each process: "); 
	for(i=0;i<pno;i++)
		{	printf("\n");
			for(j=0;j<rno;j++)
			{
					printf("\t");			
					scanf("%d",&max[i][j]);
			}	
		}	
	printf("\nEnter the number of resources currently allocated to each processes: ");
	
	//ENTERING VALUES INTO MATRIX ALLOCATION
	
	for(i=0;i<pno;i++)
		{	printf("\n");
			for(j=0;j<rno;j++)
			{		printf("\t");
					scanf("%d",&allocation[i][j]);
			}		
		}	
			
	//ENTERING VALUES INTO MATRIX NEED		
	for(i=0;i<pno;i++)
			for(j=0;j<rno;j++)
				need[i][j]=(max[i][j])-allocation[i][j];
				
	//PRINTING MATRIX NEED
	printf("NEED: ");
	for(i=0;i<pno;i++)
		{	printf("\n");
			for(j=0;j<rno;j++)
			{		printf("\t");
					printf("%d",need[i][j]);
			}		
		}						
	
	//INITIAISING FINSH AS FALSE FOR ALL PROCESSES
	
	for(i=0;i<pno;i++)
		finish[i]=0;
		

	while(flag==0)
	{
		for(i=0;i<pno;i++)
		{
	 			countr=0;
				for(j=0;j<rno;j++)
				{
					if(finish[i]==0 && need[i][j]<=available[j])
		                                countr++;
				}
						
				if(countr==rno)
				{
					for(j=0;j<rno;j++)
					 	available[j]+=allocation[i][j];
					finish[i]=1;
					// PRINTING UPDATED MATRIX AVAILABLE
					printf("\n");
					for(k=0;k<rno;k++)
					 printf(" %d",available[k]);
				}		
					
				else
				{    
				    count=0;
				    for(k=0;k<pno;k++)
				    	{
						if(finish[k]==1)
							count++;
						}	
	   	    		if(count==pno-2) // TO CHECK IF THIS PROCESS THAT CANNOT BE ALLOCATED IS THE LAST ONE. IF YES IT IS NOT SAFE
					{
						printf("\nThe system is not in safe state ");
						exit(0);
					}	
				}	
		}	
			
						
		count=0;			
		for(i=0;i<pno;i++)
			if(finish[i]==1)
				count++;
		if(count==pno)
			flag=1;
	}
		printf("CHECK");
		printf("\nThe system is in safe state");
}		
void main()
{
	bankers();
}				
	
	
		
		

				
						
					
					
				
			
	
	
	

