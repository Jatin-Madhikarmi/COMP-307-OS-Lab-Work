#include <stdio.h>
#include <unistd.h>    /* Essential for fork() */
#include <sys/types.h> /* Essential for pid_t */

int main() {
    pid_t pid;

    // The fork() system call creates a duplicate process
    pid = fork();

    if (pid < 0) { 
        // If fork returns a negative value, an error occurred
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
    else if (pid == 0) { 
        // Child process: fork() returns 0 here
        printf("CHILD: I am the child process. My PID is %d\n", getpid());
    } 
    else { 
        // Parent process: fork() returns the child's PID here
        printf("PARENT: I am the parent process. My child's PID is %d\n", pid);
    }

    return 0;
}