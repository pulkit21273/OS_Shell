#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>



void mkdirfn(int argc , char* argv[])
{
    
    for (int i = 1 ; i < argc ; i++)
    {
        int x = mkdir(argv[i],0777);
        if (x==-1)
        {
            perror("Error");
        }

        else if (x==0)
        {

            printf("Directory created !\n");
        }
    }
}

void mkdirfnthread(int argc , char* argv[])
{
    
    for (int i = 2 ; i < argc ; i++)
    {
        int x = mkdir(argv[i],0777);
        if (x==-1)
        {
            perror("Error");
        }

        else if (x==0)
        {

            printf("Directory created !\n");
        }
    }
}


void mkdirvfn(int argc, char* argv[])
{
    for (int i = 2 ; i < argc ; i++)
    {
        int x = mkdir(argv[i],0777);
        if (x==-1)
        {
            perror("Error");
        }

        else if (x==0)
        {
            printf("Directory created : %s\n" , argv[i]);
        }
    }
}

void mkdirvfnthread(int argc, char* argv[])
{
    for (int i = 3 ; i < argc ; i++)
    {
        int x = mkdir(argv[i],0777);
        if (x==-1)
        {
            perror("Error");
        }

        else if (x==0)
        {
            printf("Directory created : %s\n" , argv[i]);
        }
    }
}



int main(int argc , char* argv[])
{
    
    // for (int i=0;i<argc;i++)
    // {
    //     printf("%s ",argv[i]);
    // }

    if (strcmp(argv[0],"mkdir")==0)
    {
        if (strcmp(argv[1],"-v")==0)   
        {
            mkdirvfn(argc,argv);
        }
        else
        {  
            mkdirfn(argc,argv);
        }
    }


    else 
    {
        if (strcmp(argv[2],"-v")==0)   
        {
            mkdirvfnthread(argc,argv);
        }
        else
        {  
            mkdirfnthread(argc,argv);
        }
    }
    
    
    return 0;

}