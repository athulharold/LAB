#include <stdio.h>

void main(){
	int f,n,pf=0,i,j,flag=0,fn=0;
	int frame[10],ref[50];
	printf("Enter no of free frames: ");
	scanf("%d",&f);
	printf("Enter length of reference string: ");
	scanf("%d",&n);
	printf("Enter the reference string:");
	for(i=0;i<n;i++){
		scanf("%d",&ref[i]);
	}
	
	
	for(i=0;i<f;i++)
		frame[i]=-1;
	j=0;
	while(j<n){
		for(i=0;i<f;i++){
			if(ref[j]==frame[i]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			j++;
		}
		else{
			pf++;
			frame[fn%4]=ref[j];
			fn++;
			j++;
		}
		flag=0;
	}
				
	printf("Page faults = %d\n",pf);
}
