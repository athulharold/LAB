void createfile()
{
	char temp[10];
	printf("\nEnter the directory to which the file belongs to: ");
	gets(temp);
	for(i=0;i<=n;i++)
	{
		if(strcmp(temp,dir[i].name)==1)
	       break;
	}
	if(i==n+1)
		printf("\nInvalid directory!!");
	else
	{
		file++;
		i--;
		printf("\nEnter the name of the file: ");
		gets(dir[i].fname[file]);
	}
	printf("\nFile Created Succesfully";
			
}
