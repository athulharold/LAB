#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<stdio.h>
#include<string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct mesg_buffer { 
    long msgtype; 
    char message[100];
    int matrix[2][2]; 
} message; 

void main()
{
	int msgid,matrix[3][3],msgtype,newmatrix[3][3];
	key_t key;
	key=ftok("MessageQueue",10); //creating the key for the message queue
	//printf("%d",key);
	msgid = msgget(key, 0666 | IPC_CREAT);  //creating queue
	printf("\nEnter the input matrix: ");
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			scanf("%d",&message.matrix[i][j]);
	message.msgtype=1;
	msgsnd(msgid,&message.matrix,sizeof(matrix), 0);	//appending the message queue
	printf("\nData appended to message queue");	
	
	pid_t p=fork();
	if(p<0)
		 printf("\nChild process creation failed!!");
	else
	printf("\nChild process created\nPID: %d",p);

	if(p==0){
		//for(int i=0;i<3;i++)
			//for(int j=0;j<3;j++){
			msgrcv(msgid, &newmatrix,sizeof(newmatrix), 1, 0);		//reading from the message queue
		  //printf("%d",newmatrix[i][j]);}
		  	
		printf("Data Received is : ");
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				printf("%d",newmatrix[i][j]);
		 msgctl(msgid, IPC_RMID, NULL);
		}
}		 
		  		 	

			
