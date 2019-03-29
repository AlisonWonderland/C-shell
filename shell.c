#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>


char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;
    
    if (command == NULL) {
        perror("malloc failed");
        exit(1);
    }

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;

    while (1) {
        input = readline("mShell> ");
        command = get_input(input);

        child_pid = fork(); //new child is made to ensure that the main process/shell doesn't close
        if(child_pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        if (child_pid == 0) {
             if (execvp(command[0], command) < 0) {
                perror(command[0]);
                exit(1);
            }
        } 
        else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
        free(command);
    }

    return 0;
}