#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> 

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Process creation failed.");
        exit(1);
    }
    else if (pid == 0) {
        sleep(1);
        printf("Parent ID: %d and Child ID: %d\n", getppid(), getpid());

        printf("Child process terminating.\n");
        exit(2);//1,2,3 whatever we write. If it sends exact number status. normal termination.
        //abort(); abnormal termination.
    }
    else {

        printf("This is the parent process %d\n", getpid());

        int status;
        wait(&status);

        if(WEXITSTATUS(status)==2)printf("Child terminated normally & the status ID is: %d\n", WEXITSTATUS(status));
        else printf("Child terminated abnormally.\n");//WEXITSTATUS(status)==2

        exit(0);
    }
}
