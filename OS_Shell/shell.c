#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


void scall(char* abc)
{
    system(abc);
    return;
}


void echo(int a , char* arr[])
{
    
    if (a <= 1)
    {
        printf("Please enter an argument !\n");
    }

    else
    {
        int i;
        for (i=1;i<a;i++)
        {
            printf("%s ",arr[i]);
        }
        printf("\n");
    }
}

void echon(int a , char* arr[])
{
     
    

    if (a <= 2)
    {
        printf("Please enter an argument !\n");
    }

    else
    {
        int i;
        for (i=2;i < a ;i++)
        {
            printf("%s ",arr[i]);
        }
    }
    
}

void echohelp(int a)
{
    if (a < 1)
    {
        printf("Please enter an argument !\n");
    }

    else
    {
       
        
        printf("--help");
        printf("\n");
    }
}


void pwd()
{
    char cwd[500];
    printf("%s\n",getcwd(cwd,500));
}


void cd(int a, char* arr[])
{
    
    if (a<1)
    {
        // printf("%d",a);
        printf("Not enough parameters !\n");
    }
    else if (a==1)
    {
    
        if (chdir(arr[0])==0)
        {
            char s[100];

            printf("Directory changed !\n");
            printf("%s\n",getcwd(s,100));

        }
        else
        {
            perror("Error");
        }
    }

    else if (a>1)
    {
        printf("Too many parameters\n");
    }
}


void cdback()
{
    chdir("..");
    char s[100];
    printf("%s\n",getcwd(s,100));
}


void cdhome()
{
    chdir("/Users");
    char s[100];
    printf("%s\n",getcwd(s,100));
}


int main(int argc, char* argv[])
{

    while (1)
    {
       char str[100];
        printf("Enter Command : ");
        gets(str);
        char* token = strtok(str," ");
        char* array[250];
        int idx = 0;
        int words=0;
        while(token != NULL) 
        {
            array[idx] = token;
            token = strtok(NULL," ");
            idx++;
            words++;
            // argc++;
        }
        array[idx]=NULL;
        idx++;
        // printf("%d",words);
        



        if (strcmp(array[0],"cd")==0)
        {
            
            if (strcmp(array[1],"..")==0)
            {
                cdback();
            }
            else if (strcmp(array[1],"--")==0)
            {
                cdhome();
            }
            else
            {
                 cd(argc,&array[1]);
            }
        }   

        else if (strcmp(array[0],"pwd")==0)
        {
            pwd();
        }

        else if (strcmp(array[0],"echo")==0)
        {
            
            if (strcmp(array[1],"-n")==0)
            {
                echon(words,array); 
            }
            else if (strcmp(array[1],"--help")==0)
            {
                echohelp(words);
            }
            else
            {
                
                echo(words,array);
            }
        }



        

        else if (strcmp(array[0],"ls")==0)
        {
            if (strcmp(array[idx-2],"&t")==0)
            {
                pthread_t t;
                char threadstr[2000] = "/Users/pulkitnargotra/desktop/ls";

                for (int q = 0 ; q < idx-2 ;  q++ )
                {
                    strcat(threadstr," ");
                    strcat(threadstr,array[q]);
                }

                pthread_create(&t,NULL,scall,threadstr);
                pthread_join(t,NULL);
            }

            else
            {
            int pid = fork();
            if (pid < 0)
            {
                printf("Fork Failed !");
            }
            else if (pid == 0)
            {
                execvp("/Users/pulkitnargotra/desktop/ls",array);
            }
            else 
            {
                wait(NULL);
            }
            }
        }


        else if (strcmp(array[0],"mkdir")==0)
        {
            
            if (strcmp(array[idx-2],"&t")==0)
            {
                
                pthread_t t;
                char threadstr[2000] = "/Users/pulkitnargotra/desktop/mkdir";

                for (int q = 0 ; q < idx-2 ;  q++ )
                {
                    strcat(threadstr," ");
                    strcat(threadstr,array[q]);
                }

                pthread_create(&t,NULL,scall,threadstr);
                pthread_join(t,NULL);
            }


            else {
            int pid = fork();
            if (pid < 0)
            {
                printf("Fork Failed !");
            }
            else if (pid == 0)
            {
                
                execvp("/Users/pulkitnargotra/desktop/mkdir",array);
            }
            else 
            {
                wait(NULL);
            }
            }
        }

        else if (strcmp(array[0],"date")==0)
        {
            if (strcmp(array[idx-2],"&t")==0)
            {
                pthread_t t;
                char threadstr[2000] = "/Users/pulkitnargotra/desktop/date";

                for (int q = 0 ; q < idx-2 ;  q++ )
                {
                    strcat(threadstr," ");
                    strcat(threadstr,array[q]);
                }

                pthread_create(&t,NULL,scall,threadstr);
                pthread_join(t,NULL);
            }

            else 
            {
            int pid = fork();
            if (pid < 0)
            {
                printf("Fork Failed !");
            }
            else if (pid == 0)
            {
                execvp("/Users/pulkitnargotra/desktop/date",array);
            }
            else 
            {
                wait(NULL);
            }
            }
        }


        else if (strcmp(array[0],"cat")==0)
        {
            // printf("%s",array[idx-1]);
            if (strcmp(array[idx-2],"&t")==0)
            {
                
                pthread_t t;
                char threadstr[2000] = "/Users/pulkitnargotra/desktop/cat";

                for (int q = 0 ; q < idx-2 ;  q++ )
                {
                    strcat(threadstr," ");
                    strcat(threadstr,array[q]);
                }

                pthread_create(&t,NULL,scall,threadstr);
                pthread_join(t,NULL);
            }



            else
            {

            int pid = fork();
            if (pid < 0)
            {
                printf("Fork Failed !");
            }
            else if (pid == 0)
            {
                execvp("/Users/pulkitnargotra/desktop/cat",array);
            }
            else 
            {
                wait(NULL);
            }

            }
        }

        else if (strcmp(array[0],"rm")==0)
        {
            if (strcmp(array[idx-2],"&t")==0)
            {
                
                pthread_t t;
                char threadstr[2000] = "/Users/pulkitnargotra/desktop/rm";

                for (int q = 0 ; q < idx-2 ;  q++ )
                {
                    strcat(threadstr," ");
                    strcat(threadstr,array[q]);
                }

                pthread_create(&t,NULL,scall,threadstr);
                pthread_join(t,NULL);
            }

            
            else
            {
            int pid = fork();
            if (pid < 0)
            {
                printf("Fork Failed !");
            }
            else if (pid == 0)
            {
                execvp("/Users/pulkitnargotra/desktop/rm",array);
            }
            else 
            {
                wait(NULL);
            }
            }

        }
    else 
    {
        printf("Enter valid command !\n");
    }    
    }
    

    return 0;
}
