#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  char *page;
  int pid;

  page = sbrk(4096);
  if(page == (char*)-1){
    printf(1, "prottest: sbrk failed\n");
    exit();
  }

  *page = 'A';
  if(mprotect(page, 1) < 0){
    printf(1, "prottest: mprotect failed\n");
    exit();
  }
  printf(1, "Read-only page still reads: %c\n", *page);

  pid = fork();
  if(pid < 0){
    printf(1, "prottest: fork failed\n");
    exit();
  }
  if(pid == 0){
    *page = 'B';
    printf(1, "ERROR: protected write was allowed\n");
    exit();
  }
  wait();
  printf(1, "Parent survived child fault; page contains %c\n", *page);

  if(munprotect(page, 1) < 0){
    printf(1, "prottest: munprotect failed\n");
    exit();
  }
  *page = 'C';
  printf(1, "Writable page now contains: %c\n", *page);

  printf(1, "unaligned address rejected: %s\n",
         mprotect(page + 1, 1) == -1 ? "yes" : "no");
  printf(1, "zero length rejected: %s\n",
         mprotect(page, 0) == -1 ? "yes" : "no");
  printf(1, "range beyond process size rejected: %s\n",
         mprotect(page + 4096, 1) == -1 ? "yes" : "no");
  exit();
}
