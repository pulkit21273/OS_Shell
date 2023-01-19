#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cat(int argc, char* argv[])
{
    for (int i = 1 ; i < argc ; i++)
    {
        printf("\n------");
        printf("FILE -  %d",i);
        printf("------\n");
        FILE *filen;                    
    // filename is the argv[1] passed 
        filen = fopen(argv[i],"r");

        if (!filen)
        {
            perror("Error");
        }
        
        char nextchar=getc(filen);

        while (nextchar != EOF)
        {
            printf("%c",nextchar);
            nextchar = getc(filen);
        }

        fclose(filen);
    }
    printf("\n");
}

void catthread(int argc, char* argv[])
{
    for (int i = 2 ; i < argc ; i++)
    {
        printf("\n------");
        printf("FILE -  %d",i-1);
        printf("------\n");
        FILE *filen;                    
    // filename is the argv[1] passed 
        filen = fopen(argv[i],"r");

        if (!filen)
        {
            perror("Error");
        }
        
        char nextchar=getc(filen);

        while (nextchar != EOF)
        {
            printf("%c",nextchar);
            nextchar = getc(filen);
        }

        fclose(filen);
    }
    printf("\n");
}

void catn(int argc, char* argv[])
{
    for (int i = 2 ; i < argc ; i++)
    {
        printf("\n------");
        printf("FILE -  %d",i-1);
        printf("------\n");
        FILE *filen;                    
        // filename is the argv[1] passed 
        filen = fopen(argv[i],"r");

        if (!filen)
        {
            perror("Error");
        }

        char nextchar = getc(filen);
        int count = 2;
        printf("1\t");
        while (nextchar != EOF)
        {
            if (nextchar == '\n')
            {
                printf("\n%d\t",count);
                // continue;
                count++;
                // printf("%c",nextchar);
                nextchar = getc(filen);
            }
            else
            {
                printf("%c",nextchar);
                nextchar = getc(filen);
            }
        }

        fclose(filen);
    }
    printf("\n");
}

void catnthread(int argc, char* argv[])
{
    for (int i = 3 ; i < argc ; i++)
    {
        printf("\n------");
        printf("FILE -  %d",i-2);
        printf("------\n");
        FILE *filen;                    
        // filename is the argv[1] passed 
        filen = fopen(argv[i],"r");

        if (!filen)
        {
            perror("Error");
        }

        char nextchar = getc(filen);
        int count = 2;
        printf("1\t");
        while (nextchar != EOF)
        {
            if (nextchar == '\n')
            {
                printf("\n%d\t",count);
                // continue;
                count++;
                // printf("%c",nextchar);
                nextchar = getc(filen);
            }
            else
            {
                printf("%c",nextchar);
                nextchar = getc(filen);
            }
        }

        fclose(filen);
    }
    printf("\n");
}


void cate(int argc, char* argv[])
{
    for (int i = 2 ; i < argc ; i++)
    {
        printf("\n------");
        printf("FILE -  %d",i-1);
        printf("------\n");
        FILE *filen;                    
        // filename is the argv[1] passed 
        filen = fopen(argv[i],"r");

        if (!filen)
        {
            perror("Error");
        }

        char nextchar = getc(filen);
        
        while (nextchar != EOF)
        {
            if (nextchar == '\n')
            {
                printf("$\n");
                // continue;
                // printf("%c",nextchar);
                nextchar = getc(filen);
            }
            else
            {
                printf("%c",nextchar);
                nextchar = getc(filen);
            }
        }

        fclose(filen);
    }
    printf("\n");
}

void catethread(int argc, char* argv[])
{
    for (int i = 3 ; i < argc ; i++)
    {
        printf("\n------");
        printf("FILE -  %d",i-2);
        printf("------\n");
        FILE *filen;                    
        // filename is the argv[1] passed 
        filen = fopen(argv[i],"r");

        if (!filen)
        {
            perror("Error");
        }

        char nextchar = getc(filen);
        
        while (nextchar != EOF)
        {
            if (nextchar == '\n')
            {
                printf("$\n");
                // continue;
                // printf("%c",nextchar);
                nextchar = getc(filen);
            }
            else
            {
                printf("%c",nextchar);
                nextchar = getc(filen);
            }
        }

        fclose(filen);
    }
    printf("\n");
}


int main(int argc , char* argv[])
{   

    if (strcmp(argv[0],"cat")==0)
    {
        if (argc == 2)
        {
            cat(argc,argv);
        }
        else if (strcmp(argv[1],"-n")==0)   
        {
            catn(argc,argv);
        }
        else if (strcmp(argv[1],"-e")==0)   
        {
            cate(argc,argv);
        }
    }

    else
    {
        if (argc == 3)
        {
            catthread(argc,argv);
        }
        else if (strcmp(argv[2],"-n")==0)   
        {
            catnthread(argc,argv);
        }
        else if (strcmp(argv[2],"-e")==0)   
        {
            catethread(argc,argv);
        }

    }
    
    return 0;
}