#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        signal(SIGUSR1, signal_handler);
        pause(); // Wait for a signal
    } else if (pid > 0) { // Parent process
        sleep(1); // Give the child time to set up
        kill(pid, SIGUSR1);
        printf("Parent sent signal\n");
    } else {
        perror("fork failed");
    }

    return 0;
}
