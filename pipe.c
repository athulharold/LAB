#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<stdio.h>
#include<string.h>

int main()
{
	int fd[2];
	pid_t p;
	char str[10],newstr[10];
	if (pipe(fd)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    if (pipe(fd)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
	
	
	printf("\nEnter the input string: ");
	scanf("%s",str);
	p=fork();
	printf("Process Created; ID: %d ",p);
	write(fd[1],str,10);
	read(fd[0],newstr,10);
	printf("The string is: %s",newstr);
}
