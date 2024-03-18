// Single level directory

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
	char dname[10],fname[10][10];
	int fcnt;
}dir;
void main()
{
	int i,ch;
	char f[30];
	dir.fcnt=0;
	printf("\nEnter the name of directory: ");
	scanf("%s",dir.dname);
	printf("\n1.Create file\n2.Delete file\n3.Search file\n4.Display files\n5.Exit\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the name of the file: ");
				scanf("%s",dir.fname[dir.fcnt++]);
				break;
			case 2:
				printf("Enter the name of the file: ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f,dir.fname[i])==0)
					{
						printf("File %s is deleted",f);
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						break;
					}
				}
				if(i==dir.fcnt)
					printf("File %s not found",f);
				else
					dir.fcnt--;
				break;
			case 3:
				printf("\nEnter the name of the file: ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f,dir.fname[i])==0)
					{
						printf("File %s is found",f);
						break;
					}
				}
				if(i==dir.fcnt)
					printf("%s is not found",f);
				break;
			case 4:
				if(dir.fcnt==0)
					printf("\nDirectory is empty");
				else
				{
					printf("\nThe files are: ");
						for(i=0;i<dir.fcnt;i++)
							printf("\t%s",dir.fname[i]);
				}
				break;
			default:
				exit(0);
		}
	}
}
