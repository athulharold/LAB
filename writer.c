#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message{
	long type;
	int mat[3][3];
}message;

void main(){
	key_t key;
	int id,i,j;
	key=ftok("progfile",65);
	id=msgget(key,0666|IPC_CREAT);
	
	msgrcv(id,&message,sizeof(message),1,0);
	printf("Diagonalelements are:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j)
				printf("%d\t",message.mat[i][j]);
		}	
	}
	printf("\n");
	
	
}
