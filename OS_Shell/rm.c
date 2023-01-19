#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>

void rm(int argc, char* argv[])
{
   int e = remove(argv[1]);

    if (e!=0)
    {
        perror("Error");
    }
}


void rmthread(int argc, char* argv[])
{
    
    int e = remove(argv[2]);
    if (e!=0)
    {
        perror("Error");
    }

}


void rmv(int argc, char* argv[])
{
    // printf("%s\n",argv[2]);
    int e = remove(argv[2]);

    if (e!=0)
    {
        perror("Error");
    }
    else if (e==0)
    {
         printf("%s\n",argv[2]);
    }
       
}


void rmvthread(int argc, char* argv[])
{
    
    // printf("%s\n",argv[3]);
    int e = remove(argv[3]);
    if (e!=0)
    {
        perror("Error");
    }
    else if (e==0)
    {
         printf("%s\n",argv[3]);
    }
}



void rmi(int argc, char* argv[])
{
    
    printf("Do you want the file to be deleted ? [Y/N]\n");
    char x;
    scanf("%c",&x);
    
    // printf("%d\n",argc);
    if (x=='Y')
    {
        
        // printf("%d\n",remove(argv[2]));
        int e = remove(argv[2]);
        if (e == 0)
        {
            printf("File deleted successfully !\n");
        }
        else
        {
            printf("Invalid file name !\n");
        }
        
        
        // int y = remove(argv[1]);
        // printf("%d",y);
        
    }

    else
    {
        printf("File Not deleted !");
        printf("\n");
    }

}


void rmithread(int argc, char* argv[])
{
    
    printf("Do you want the file to be deleted ? [Y/N]\n");
    char x;
    scanf("%c",&x);
    
    if (x=='Y')
    {
        
        int e = remove(argv[3]);
        if (e==0)
        {
            printf("File deleted successfully !\n");
        }
        else
        {
            printf("Invalid file name !\n");
        }
        
    }

    else
    {
            printf("File Not deleted !");
            printf("\n");
    }
}



int main (int argc, char* argv[])
{
    if (strcmp(argv[0],"rm")==0)
    {
        if (argc==2)
        {
            rm(argc,argv);
        }
        else if (strcmp(argv[1],"-i")==0)
        {
            
            rmi(argc,argv);
        }
        else if (strcmp(argv[1],"-v")==0)
        {
            rmv(argc,argv);
        }
    }
    
    else
    {
        if (argc==3)
        {
            rmthread(argc,argv);
        }
        else if (strcmp(argv[2],"-i")==0)
        {

            rmithread(argc,argv);
        }
        else if (strcmp(argv[2],"-v")==0)
        {
            rmvthread(argc,argv);
        }
    }
    

    return 0;

}