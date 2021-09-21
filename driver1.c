/*
Dinesh Bhandari
1001802374
Assignment 2
David Levine
CSE 3320-001
// source from profeser code
//https://stackoverflow.com/questions/29182242/creating-multiple-processes-in-c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define size 5

int main(){
 char buffer[10];
 int procs[size],n;
 int process,process2,process1, process3,process4;   // total processes ids


//https://www.geeksforgeeks.org/pipe-system-call/
 if(pipe(procs) < 0)
	exit(1);
				write(procs[1], "./u", sizeof("./u"));     /* write pipe */                   //https://pubs.opengroup.org/onlinepubs/007904875/functions/write.html
printf("Enter:\n 1 for normal process call \n 2 for 2 process call \n 4 for 4 process call \n 10 for 10 process call \n");
scanf("%d", &n);


int x=0;
if(n==1||n==10||n==2||n==4)
{	switch(n){
	case 1:
		read(procs[0], buffer, 5);    /* read pipe */                               //https://pubs.opengroup.org/onlinepubs/007904875/functions/read.html
		execv(buffer,NULL);
		break;


	case 2:
			  read(procs[0], buffer, 5);    /* read pipe */
				process = fork();
				if(process==0)
				execv(buffer,NULL);
				execv(buffer,NULL);
		break;
	case 4:


			  read(procs[0], buffer, 5);    /* read pipe */
				process1 = fork();
				process2 = fork();
				if(process1==0)
				execv(buffer,NULL);
				if(process2==0)
				execv(buffer,NULL);
				if(process1!=0)
				execv(buffer,NULL);
				if(process2!=0)
				execv(buffer,NULL);
		break;
	case 10:
			read(procs[0], buffer, 5);   /* read pipe */
				process = fork();
				process1 = fork();
				process2 = fork();
				if(process==0){
				process3 = fork();
				execv(buffer,NULL);}
				if(process1==0){
				process4 = fork();
				execv(buffer,NULL);}
				if(process2==0)
				execv(buffer,NULL);
				if(process3==0)
				execv(buffer,NULL);
				if(process4==0)
				execv(buffer,NULL);
				if(process4!=0)
				execv(buffer,NULL);
				if(process3!=0)
				execv(buffer,NULL);
				if(process2!=0)
				execv(buffer,NULL);
				if(process1!=0)
				execv(buffer,NULL);
				if(process!=0)
				execv(buffer,NULL);

		break;
	}
	}
printf("\n no process for the no found ");

 return 0;
}
