Operating System Lab Examination (MA3105)

Name: R.Rahul
Roll No.: 2401MC49


Question 1: Page Protection using mprotect() and munprotect()

1. Modified vm.c to add page-protection logic that clears or sets the PTE_W bit for the requested pages.
2. The implementation checks page alignment, valid length, process address-space limits, and whether every page is present.
3. The TLB is flushed after updating page-table entries by reloading CR3.
4. Updated defs.h, syscall.h, syscall.c, sysproc.c, user.h, and usys.S to declare, register, and expose the mprotect() and munprotect() system calls.
5. Added prottest.c to test read-only access, a child-process write fault, restoring write permission, and invalid arguments.
6. Updated the Makefile to include the prottest user program.


Question 2: Priority-Based CPU Scheduler

1. Modified proc.h to add a priority field to struct proc, and proc.c to initialize each new process with priority 10.
2. Updated scheduler() in proc.c to select the RUNNABLE process with the smallest priority number.
3. Added set_priority() in proc.c to validate priorities from 1 to 20, update the process priority while holding ptable.lock, and return the old priority.
4. Updated defs.h, syscall.h, syscall.c, sysproc.c, user.h, and usys.S to declare, register, and expose the set_priority() system call.
5. Added schedtest.c to set the parent priority, create three children with priorities 5, 10, and 15, run CPU-bound work, and wait for them to finish.
6. Updated the Makefile to include the schedtest user program.
