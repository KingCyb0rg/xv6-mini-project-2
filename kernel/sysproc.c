#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
#include "pstat.h"

int counter=0;

int
sys_fork(void)
{
  return fork();
}

//////////// your code here  /////////////////////////////////////////////////////////////////////////////////////////////////////
/////we use this system call for changing the number of tickets of some process
/////remember by default every process has just 1 ticket.
///  because you are calling assigntickets(ticketsGotIt) which is define in proc.c you have to update defs.h with this new system call
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HERE THE PROTOTYPE
//int sys_assigntickets(void)
//{
//	int ticketsGotIt
//	if (argint(0, &ticketsGotIt) < 0)  //this is the way to pass an integer as a parameters in sysproc.c, will pass this tickets in the experiment
//	{
//		return -1;  //validation line	
//	}
//	else{
//		return assigntickets(ticketsGotIt); //assigntickets big implementation is in pro.c
//	}
//}
//////////// your code here  /////////////////////////////////////////////////////////////////////////////////////////////////////
/////we use this system call for filling out the arrays of pstat data structure
/////So, remember to include here the pstat.h header file 
///  because you are calling assigntickets(ticketsGotIt) which is define in proc.c you have to update defs.h with this new system call
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int sys_saveData(void)
//{
//	struct pstat *pTable; //create a pointer able to point to objects of the type pstat//
//	if(argptr(0, (void *)&pTable, sizeof(*pTable)) < 0){ //this is the way to pass a pointer to an object as a parameter in sysproc.c, will pass this tickets in the experiment
//		return -1;  //validation
//	}
//	if(pInfo == NULL){  //validation 
//		return -1;
//	}			
//	saveData(pTable);  //call the getpinf() in proc.c 		
//	return 0;
//}
//////////////////////////////////////////////////////
	
	int
sys_exit(void)
	
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}
int
sys_cluis(void)
{
  return counter;
}

int
sys_getpid(void)
{ 
  counter = counter +1;
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getpinfo(void)
{
  struct pstat *pTable;
  if(argptr(0, (void *)&pTable, sizeof(*pTable)) < 0){
    return -1;
  }
  if(pTable == NULL){
    return -1;
  }
  // pTable = NULL
  // unsigned int number = (unsigned int)&pTable;
  getpinfo(pTable);
  return 0;
}
