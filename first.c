#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process ID: %d\n", getpid());
    char a[]="OS practices is so entertaining";// we can use read() to take direct input from user.
    //char a[15]
    // int p=read(0,a,15);
    write(0,a,15);//It actually works like read in practical
    printf("\n");
    return 0;
}
