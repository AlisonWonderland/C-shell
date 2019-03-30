# mShell
A basic unix shell that I created with the help of a tutorial to learn about system calls.

## Supported commands
* ls
* pwd
* cd

Also for the moment it can only support 8 commands/flags. The reason for this is that 
I allocate only 8 char*'s for the command buffer.

## What I learned
**System calls**
* Fork(): Learned that fork() will duplicate the running program/process its
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

## Tutorial link
https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/