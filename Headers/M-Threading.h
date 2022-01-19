#ifndef MT_HEADER
#define MT_HEADER

//Global Librairies
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//Main Defines
#define CUPCAKE_VERSION "1.0"

//Color Defines
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KPNK  "\x1b[95m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

void StartThreads();

void* Printer(void* threadid) {
   long tid; //We Initialize A Local Thread ID Variable
   tid = (long)threadid; //And Store Acutla Thread ID Inside It After Converting It Into A Long Using '(long)' Right Before
   printf(" %s[Thread %d]%s : Hello There ! \n", KGRN, tid, KWHT); //We Print Some Text And Also The Thread ID Of The Thread That Printed The Text
   pthread_exit(NULL); //And Then We Exit The Thread (Thread Termination)
}

void StartThreads()
{
   int t_numb;
   printf(" Threads Number >> ");
   scanf("%10d", &t_numb);
   printf("\n");

   pthread_t thread_number[t_numb]; //Initating Thread Numbers
   int rc, i;

   for(i = 1; i <= t_numb; i++) { //Loop To Create The Threads
      printf(" %s[INFO]%s Creating Thread Number [%d]... \n", KBLU, KWHT, i); //Telling User We're Going To Try To Create A Thread
      rc = pthread_create(&thread_number[i], NULL, Printer, (void*)i); //Creating The Thread
      if (rc) {
         printf(" %s[ERROR]%s An Error Occured While Creating Thread [%d] \n", KRED, KWHT, rc); //Error While Creating It :(
         exit(-1); //We Exit To Avoid Damaging The Machine
      }
   }
   pthread_exit(NULL); //Terminating All Threads And Exiting The Program
}
#pragma GCC diagnostic pop

#endif
