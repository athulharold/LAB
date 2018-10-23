#include<stdio.h>
#include<stdlib.h>
void main(){
	int dq[10],n;
	int head,count=0,high,i,temp;
	printf("Enter how many items in the disk queue: ");
	scanf("%d",&n);
	printf("Enter the disk queue: ");
	for (i=0;i<n;i++){
		scanf("%d",&dq[i]);
	}
	printf("Enter current head position: ");
	scanf("%d",&head);
	printf("Enter Highest Cylinder no. possible: ");
	scanf("%d",&high);
	for(i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(dq[j]>dq[j+1]){
				temp=dq[j];
				dq[j]=dq[j+1];
				dq[j+1]=temp;
			}
		}
	}	
	printf("Schedule: %d ",head);
	for(i=0;i<n;i++){
		if(dq[i]>head){
			break;
		}
	}
	count+=abs(head-dq[i-1]);
	head=dq[i-1];
	printf("%d ",head);
	for(int j=i-2;j>=0;j--){
		printf("%d ",dq[j]);
		count+=abs((dq[j]-head));
		head=dq[j];
	}
	if(head!=0){
		count+=head;
		head=0;
		printf("%d ",head);
	}
	for(int j=i;j<n;j++){
		printf("%d ",dq[j]);
		count+=abs((dq[j]-head));
		head=dq[j];
	}
	if(head!=high){
		count+=abs(head-high);
		printf("%d ",high);
	}
	
	printf("\nTotal Head Count is %d\n",count);
}
	
		
		
			

