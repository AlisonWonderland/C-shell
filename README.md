# mShell
A basic unix shell that I created with the help of a tutorial to learn about the different system calls.

## Supported commands
As of now it only supports builtin commands like:
* ls
* pwd

In the future I'll modify this shell to support cd and maybe piping.

## What I learned
**System calls**
* Fork(): Learned that fork() will duplicate the running program/process its
called in and then the duplicate will continue/start on the code after the fork() call.
You want to use fork() in the shell for any user command so that if any 
issues occur with processing the command, the shell/parent process can continue 
running.
*waitpid():

## Tutorial link
https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/