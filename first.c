#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process ID: %d\n", getpid());
    char a[]="OS practices is so entertaining";// we can use read() to take direct input from user.
    write(0,a,12);//It actually works like read in practical
    printf("\n");
    return 0;
}
