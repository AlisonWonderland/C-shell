# mShell
A basic unix shell that I created with the help of a tutorial to learn about system calls.

## How to compile
    gcc shell.c -lreadline -o shell
## To run/execute in terminal
    ./shell

## Supported commands
* ls
* pwd
* cd

Also for the moment it can only support 8 commands/flags. The reason for this is that 
I allocate only 8 char*'s for the command buffer.

## What I learned about..
**System calls and other functions**
* fork(): Learned that fork() will duplicate the running program/process its
called in and then the duplicate will continue/start on the code after the fork() call.
You want to use fork() in the shell for almost any user command so that if any 
issues occur with processing the command, the shell/parent process can continue 
running.
* waitpid(): Used to prevent child processes from becoming "zombies", meaning that
that the process has finished executing, but is still in the process table(explained
further on). In this shell its used in the parent to wait for the child to finish
and be removed from memory/process table.
* execvp(): Will replace the process its called in with the program specified in
the first argument. This can be another executable C program or an inbuilt command
like 'ls'.
* perror(): Will print out an error message based on the value of the errno
variable. The errno variable stores the value of the error condition. The argument
for perror is a string that you can add to the beginning of the error message.
* chdir(): Changes the directory of the parent process to the one in the argument of 
the function call. I use it when the user enters 'cd' since it is not a builtin 
command.
* getcwd(): Will write the current directory to cwd(short for 'current working directory') 
and return cwd. I use it to print out the current directory to the shell so that the
user knows in what directory their in.
* readline(): Learned that this is one way of getting input from the user in C.

**Miscellaneous Things**
* Process control block(PCB): A data structure that contains information about each process
like the pid, program counter, etc.
* Process table: An array of PCBs used by an OS to keep track of processes. When a process 
is done, its associated PCB will be removed.

## To do list
* mkdir 
* history

## Tutorial link
https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/

## Sources for some of what I discussed here. For future reference.
**Process table and PCB:**
* https://www.geeksforgeeks.org/operating-system-process-table-process-control-block-pcb/
https://computer.howstuffworks.com/operating-system6.htm

