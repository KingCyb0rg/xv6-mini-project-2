#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"

int main()
{
    int rc, i;
    double p=0;

    for(i = 1; i<= 5; i++)
    {
       rc = fork();
       if(rc < 0)
       {
        printf(1, "Fork failed\n");
        return -1;
       }
       else if (rc == 0){
            assigntickets(i*10);
            for(;;)
                p++;
       }
    }
    exit();
}