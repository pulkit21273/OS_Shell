#include <stdio.h>
#include <time.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (strcmp(argv[0],"date")==0)
    {
        time_t Time;
        time(&Time);
        printf("%s",ctime(&Time));
    }
    else
    {
        time_t Time;
        time(&Time);
        printf("%s",ctime(&Time));
    }
    return 0;
}