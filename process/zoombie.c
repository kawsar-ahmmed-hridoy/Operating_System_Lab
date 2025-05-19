#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
   pid_t pid=fork();

   if(pid<0)printf("Process creation failed\n");
   else if(pid==0){// this is a child process. parent thakbe.
      printf("Parent ID: %d and Child ID: %d\n", getppid(), getpid());

   }
   else{
      wait(NULL);
      sleep(3);//this will prevent becoming zoombie.
      printf("Parent ID: %d and Child ID: %d\n", getpid(), pid);
   }
   return 0;
}
