#include<stdio.h>
#include<unistd.h>
int isPrime(int a){
	int i;
	for(i=2;i<a;i++){
		if(a%i==0)
			return 0;
	}
	if(a==1 || a==0)
		return 0;
	return 1;
}
void main(){
	int a[100],n,sp=0,snp=0,fr,i;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter numbers:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	fr=fork();
	for(i=0;i<n;i++){
		if(isPrime(a[i])){
			if(fr==0)
				sp+=a[i];
		}
		else{
			if(fr!=0)
				snp+=a[i];
		}
	}
	if(fr==0)
		printf("Sum of prime: %d\n",sp);
	else
		printf("Sum of non prime: %d\n",snp);
}
	
