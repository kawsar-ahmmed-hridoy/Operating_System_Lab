#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
   pid_t pid=fork();
   if(pid<0)printf("Process creation failed\n");
   else if(pid==0){// this is a child process. parent thakbe.

      sleep(2);//This will go for sleep & else condition will be executing.

      printf("Orphaning starts...\n");//parent agee execute hoye jabe.
      
      printf("Parent ID: %d and Child ID: %d\n", getppid(), getpid());

   }
   else{
      printf("Parent ID: %d and Child ID: %d\n", getpid(), pid);
   }
   return 0;
}
