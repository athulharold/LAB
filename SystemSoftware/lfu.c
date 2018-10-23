#include<stdio.h>
int frame[10];
int ref[20];
int nf=0,nr=0;
int max_f=10;
int fault=0;
int freq[20][2];
int nfreq=0;

int findinFrame(int pno){
	for(int i=0;i<nf;i++){
		if(frame[i]==pno)
			return i;
	}
	return -1;
}
int findinfreq(int pgno){
	for(int i=0;i<nfreq;i++){
		if(freq[i][0]==pgno)
			return i;
	}
	return -1;
}
void prepare_freq(){
	for(int i=0;i<nr;i++){
		if(findinfreq(ref[i])==-1)
			freq[nfreq++][0]=ref[i];
			freq[nfreq-1][1]=0;
	}
}
int find_least(){
	int ind=findinfreq(frame[0]);
	int min=freq[ind][1];
	int iof=0;
	for(int i=1;i<nf;i++){
		ind=findinfreq(frame[i]);
		if(freq[ind][1]<min){
			min=freq[ind][1];
			iof=i;
		}
	}
	return iof;
}
		
void lfu(){
	prepare_freq();
	for(int i=0;i<nr;i++){
		int ind=findinfreq(ref[i]);
		freq[ind][1]++;
		if(findinFrame(ref[i])==-1){
			fault++;
			if(nf<max_f){
				printf("\n %d inserted",ref[i]);
				frame[nf++]=ref[i];//to be refined
			}
			else{
				int i_lup=find_least();
				printf("\n %d removed %d inserted",frame[i_lup],ref[i]);
				frame[i_lup]=ref[i];
			}
				
		}
	}


	printf("\n %d page faults",fault);
	printf("\n The frames are currently allocated as: ");
	for(int i=0;i<max_f;i++)
	{
		printf(" %d",frame[i]);
	}	

}


void lfu_call(){
	printf("\n Enter length of reference string:");
	scanf("%d",&nr);
	printf("\n Enter max size of frame");
	scanf("%d",&max_f);
	printf("\n Enter reference string");
	for(int i=0;i<nr;i++)
		scanf("%d",&ref[i]);

	lfu();
}
 

void main()
{
	lfu_call();
}	

