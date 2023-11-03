#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main()
{
    int i;
    struct pstat table;
    ps(&table);
    for (i = 0; i < 25; i++)
        printf(1, "Use: %d   Priority: %d   PID: %d   Ticks: %d   Passvalue: %d\n", table.inuse[i], table.priority[i], table.pid[i], table.ticks[i], table.passvalue[i]);
    exit();    
}