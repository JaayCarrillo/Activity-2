#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void wakeUp();
 void main(){
   int pid;
   // fork to create the child process
   if(pid = fork() < 0)
   {
     perror("Fork");

     exit(1);
   }
   // if pid is 0, child created and executes
   if (pid ==0){
     
     // sleep signal
     sleep(10);
   }
   // if >0, parent will be executed
   else{
     // 30 iterations
     for(int i=0; i<30; i++){
       printf("Parent loop iteration: %d\n", i+1);
       sleep(1);
       // if count reaches 5, send WAKEUP signal
       if(i == 4){
         
         sleep(1);
       }
     }
     exit(1);
   }
 }

 // Once wakeup signal is received, do 20 iterations and sleep each second
 void wakeUp(){
   
   for(int i=0; i<20; i++){
     printf("Child loop iteration: %d\n", i+1);
     sleep(1);
   }
   exit(1);
 }
