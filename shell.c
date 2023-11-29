#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command) {
    // Fork a new process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        // Child process
        char *args[MAX_INPUT_SIZE];
        char *token = strtok(command, " ");
        int i = 0;

        // Tokenize the command
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Execute the command
        execvp(args[0], args);

        // If execvp fails
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        // Print shell prompt
        printf("$ ");
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Exit the shell if the user enters 'exit'
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Execute the command
        execute_command(input);
    }

    return 0;
}

