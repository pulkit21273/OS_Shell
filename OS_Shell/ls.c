#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ls()
{
    struct dirent **nlst;

    char path[500];
    getcwd(path,500);

    int arr = scandir(path,&nlst,0,alphasort);
    
    if (arr<0)
    {
        printf("Error : No files !");
        exit(0);
    }
    else
    {
        for (int i=0;i<arr;i++)
        {
            if ((nlst[i]->d_name[0]) == '.')                // HIDDEN FILES
            {
                continue;
            }
            else if ((nlst[i]->d_name[0]) != '.')
            {
                printf("%s\t\t",nlst[i]->d_name);
            }
        }
        
    }
    printf("\n");
}




void ls1()
{
    struct dirent **nlst;

    char path[500];
    getcwd(path,500);

    int arr = scandir(path,&nlst,0,alphasort);
    
    if (arr<0)
    {
        printf("Error : No files !");
        exit(0);
    }
    else
    {
        for (int i=0;i<arr;i++)
        {
            if ((nlst[i]->d_name[0]) == '.')                // HIDDEN FILES
            {
                continue;
            }
            else if ((nlst[i]->d_name[0]) != '.')
            {
                printf("%s\n",nlst[i]->d_name);
            }
        }
    }
    printf("\n");
}

void lsa()
{
    struct dirent **nlst;

    char path[500];
    getcwd(path,500);

    int arr = scandir(path,&nlst,0,alphasort);
    
    if (arr<0)
    {
        printf("Error : No files !");
        exit(0);
    }
    else
    {
        for (int i=0;i<arr;i++)
        {
            
            if ((nlst[i]->d_name[0]) == '.')
            {
               
                printf("%s\t\t",nlst[i]->d_name);
            }
            else if ((nlst[i]->d_name[0]) != '.')
            {
                
                printf("%s\t\t",nlst[i]->d_name);
            }

        }
    }
    printf("\n");
}



int main(int argc , char* argv[])
{


    if (strcmp(argv[0],"ls")==0)
    {
        if (argc == 1)
        {
            ls();
        }
        else if (strcmp(argv[1],"-a")==0)   
        {
            lsa();
        }
        else if (strcmp(argv[1],"-1")==0)   
        {
            ls1();
        }
    }

    else
    {
        if (argc == 2)
        {
            ls();
        }
        else if (strcmp(argv[2],"-a")==0)   
        {
            lsa();
        }
        else if (strcmp(argv[2],"-1")==0)   
        {
            ls1();
        }
    }
    
    


    return 0;
}