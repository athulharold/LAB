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
	message.type=1;
	printf("Enter elements of Matrix:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&message.mat[i][j]);
	msgsnd(id,&message,sizeof(message),0);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf("\t%d\t",message.mat[i][j]);
		printf("\n");
	}
	
}
