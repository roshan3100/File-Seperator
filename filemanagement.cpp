#include <stdio.h>
#include <dirent.h>
#include <strings.h>
#include <conio.h>

void main()
{
    int l,g,k=0,i,j;
    char gr[100];
    char tr[100];
    char sd[100];
    char fd[100];
    char jd[100];
    char hd[100];
    char nm[100];
    char filename[100];
    struct dirent *de; //Pointer for directory entry
    printf("Enter a directory path and name to separate files in store in separate folder (C:/name):");
    gets(filename);
    DIR *dr = opendir(filename);    // opendir() returns a pointer of DIR type.
	if (dr == NULL)     // opendir returns NULL if couldn't open directory
        {
		printf("Could not open current directory" );
		return 0;
        }
    while ((de = readdir(dr)) != NULL)  // it reads the file name and directory name present the directory.
    {
        for(i=0;de->d_name[i]!='\0';i++)
			{
			    gr[i]=de->d_name[i];
			}
			gr[i]='\0';
        strcpy(hd,filename);
        strcpy(sd,gr);
        l=strlen(sd);
    for(i=l,j=0;sd[i-1]!='.' && i>=0;i--)
    {
        fd[j]=sd[i-1];
        j++;
    }
    fd[j]='\0';
    if(i>0)
    {
    g=strlen(fd);
    for(i=g,j=0;i!=0;i--)
    {
        jd[j]=fd[i-1];
        j++;
    }
    jd[j]='\0';
    strcat(jd," files");
    strcat(hd,"\\\\");
    strcpy(nm,hd);
    strcat(nm,jd);
    strcat(hd,gr);
    DIR *dt = opendir(nm);
	if (dt == NULL)
    {
    mkdir(nm);
    }
    closedir(dt);
    strcat(nm,"\\\\");
    strcat(nm,gr);
    rename(hd,nm);
}
    }
printf("\nCompleted");
printf("\nCheck Out in %s.\n",filename);
rewinddir(dr);      //rewinding the directory to the 1st position.
printf("Files are:\n");
	while ((de = readdir(dr)) != NULL)
			{printf("%s\n", de->d_name);
			}
	closedir(dr);
	getch();
}
