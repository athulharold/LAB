#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir2[10];


void twolevel()
{
int i,ch,dcnt,k;
char f[30], d[30],new[30];

dcnt=0;
while(1)
{
printf("\n\n 1. Create Directory\t 2. Create File\t 3. Delete File");
printf("\n 4. Search File \t \t 5. Display \t 6.Rename file \t7.Rename directory  \t 8. Exit \t Enter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter name of directory -- ");
scanf("%s",d);
int u=0;
for(i=0;i<dcnt;i++){
if(strcmp(d,dir2[i].dname)==0){
printf("\n Directory already exists");
u=1;
break;}
}
if(u==0){
//scanf("%s", dir2[dcnt].dname);
strcpy(dir2[dcnt].dname,d);
dir2[dcnt].fcnt=0;
dcnt++;
printf("Directory created");
}
break;
case 2: printf("\n Enter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
if(strcmp(d,dir2[i].dname)==0)
{
printf("Enter name of the file -- ");
scanf("%s",f);
int e=0;
for(k=0;k<dir2[i].fcnt;k++)
{
if(strcmp(f, dir2[i].fname[k])==0){
	e=1;
	break;}
}
//scanf("%s",dir2[i].fname[dir2[i].fcnt]);
if(e==0){
strcpy(dir2[i].fname[dir2[i].fcnt],f);
dir2[i].fcnt++;
printf("File created");
}
else
printf("\n File already exists");
break;
}
if(i==dcnt)
printf("Directory %s not found",d);
break;
case 3: printf("\nEnter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{
if(strcmp(d,dir2[i].dname)==0)
{
printf("Enter name of the file -- ");
scanf("%s",f);
for(k=0;k<dir2[i].fcnt;k++)
{
if(strcmp(f, dir2[i].fname[k])==0)
{
char y;
printf("\n Are you sure to delete this file(y/n)?");
scanf("%s",&y);
if(y=='y'){
printf("File %s is deleted ",f);
dir2[i].fcnt--;
strcpy(dir2[i].fname[k],dir2[i].fname[dir2[i].fcnt]);}
goto jmp;
}
}
printf("File %s not found",f);
goto jmp;
}
}
printf("Directory %s not found",d);
jmp : break;
case 4: printf("\nEnter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{

if(strcmp(d,dir2[i].dname)==0)
{
printf("Enter the name of the file -- ");
scanf("%s",f);
for(k=0;k<dir2[i].fcnt;k++)
{
if(strcmp(f, dir2[i].fname[k])==0)
{
printf("File %s is found ",f);
goto jmp1;
}
}
printf("File %s not found",f);
goto jmp1;
}
}
printf("Directory %s not found",d);
jmp1: break;
case 5: if(dcnt==0)
printf("\nNo Directory's ");
else
{
printf("\nDirectory\tFiles");
for(i=0;i<dcnt;i++)
{
printf("\n%s\t\t",dir2[i].dname);
for(k=0;k<dir2[i].fcnt;k++)
printf("\t%s",dir2[i].fname[k]);
}
}
break;
case 6:
printf("\nEnter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{

if(strcmp(d,dir2[i].dname)==0)
{
printf("Enter the name of the file -- ");
scanf("%s",f);
for(k=0;k<dir2[i].fcnt;k++)
{
if(strcmp(f, dir2[i].fname[k])==0)
{
printf("File %s is found ",f);
printf("\n Enter new name of the file:");
scanf("%s",new);
//check if exists
//printf("Enter the name of the file -- ");
//scanf("%s",f);
int p;
for(p=0;p<dir2[i].fcnt;p++)
{
if(strcmp(new, dir2[i].fname[p])==0)
{
printf("File name already exists ");
goto jmpl1;
}
}
strcpy(dir2[i].fname[k],new);
printf("\n file renamed sucessfully");
goto jmpl1;
}
}
printf("File %s not found",f);
goto jmpl1;
}
}
printf("Directory %s not found",d);
jmpl1: break;
case 7:
printf("\n Enter name of the directory -- ");
scanf("%s",d);
int fl=0;
for(i=0;i<dcnt;i++){
if(strcmp(d,dir2[i].dname)==0)
{
	printf("\n Directory found");
	printf("\n Enter new name:");
	scanf("%s",new);
	//check if exists
	int p;
	for(p=0;p<dcnt;p++){
	if(strcmp(new,dir2[p].dname)==0)
	{
	printf("\n Directory name already exists!");
	//printf("\n Enter new name:");
	//scanf("%s",new);

	//strcpy(dir2[i].dname,new);
	//printf("\n Directory renamed sucessfully");
	fl=0;
	break;
	}
	}
	if(fl!=0){
	
	strcpy(dir2[i].dname,new);
	printf("\n Directory renamed sucessfully");
	fl=1;}
	break;
}
}
if(fl==0)
printf("\n Rename unsucessfull");
break;
default:exit(0);
}
}

}

void main()
{
		twolevel();
		
}
