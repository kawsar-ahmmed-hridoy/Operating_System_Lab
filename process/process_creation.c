#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(){
   pid_t parent=getpid();
   printf("The parent is ID: %d\n", parent);
   pid_t pid=fork();
   if(pid<0)printf("Process creation failed\n");
   else if(pid==0){// this is a child process. parent thakbe.
      sleep(1);
      printf("Parent ID: %d and Child ID: %d\n", getppid(), getpid());
      // Sometimes it may show different parent ID. Because the parent may terminate before child.
      //We can solve it by sleeping the chaild process || making wait the parent process.
   }
   else{
      printf("This is the parent process %d\n", getpid());
      wait(NULL);// You can use anyone of sleep or wait or both to handle it.
   }
}
