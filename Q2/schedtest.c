#include "types.h"
#include "stat.h"
#include "user.h"

static void
work(int priority)
{
  volatile uint i;

  for(i = 0; i < 50000000; i++)
    ;
  printf(1, "Priority %d finished\n", priority);
}

int
main(void)
{
  int pid;
  int priorities[3] = {5, 10, 15};
  int i;

  if(set_priority(getpid(), 1) < 0){
    printf(1, "schedtest: failed to set parent priority\n");
    exit();
  }

  for(i = 0; i < 3; i++){
    pid = fork();
    if(pid < 0){
      printf(1, "schedtest: fork failed\n");
      exit();
    }
    if(pid == 0){
      work(priorities[i]);
      exit();
    }
    if(set_priority(pid, priorities[i]) < 0){
      printf(1, "schedtest: failed to set child priority\n");
      exit();
    }
  }

  wait();
  wait();
  wait();
  printf(1, "Done\n");
  exit();
}
