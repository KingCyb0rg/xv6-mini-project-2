#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[])
{
    int i;
    struct pstat table;
    getpinfo(&table);
    for (i = 0; i < 25; i++)
    {
        // if (!table.inuse[i])
        //     continue;
        printf(1, "Use: %d   Tickets: %d   PID: %d   Ticks: %d   Strides: %d   Passvalue: %d\n", table.inuse[i], table.tickets, table.pid, table.ticks, table.stride, table.passvalue);
    }
    exit();    
}