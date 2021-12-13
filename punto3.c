#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    int status;
    int value = -1;
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        sleep(1);
        srand(time(0));
        exit(rand()%10);
    } else {
        // parent goes down this path (original process)
        int wc = wait(&status);
        if(WIFEXITED(status)) {
           value = WEXITSTATUS(status);
        }
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int) getpid());
        printf("child's value is:%d\n", value);
    }
    return 0;
}