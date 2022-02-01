/*
Dinesh Bhandari
1001802374
Assignment 1
David Levine
CSE 3320-001
Major Source file: file provided by profeser at class myshell.c

*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include <assert.h>
#include <time.h>

int main(void) {
    pid_t child;
    DIR * d;
    struct dirent * de;
    int i,j,c, k,newdi,filessize,x;
    char s[256], cmd[256],diarray[256][256],newdir[256], *files[5000],sa[2000];
    time_t t;
    char *file_names[5000],a;



    while(1){
      t = time( NULL );  //  displaays the time from 1/1/1970 00:00 hrs
      printf( "\nTime: %s\n", ctime( &t ));   //  displaays the current time
      printf("-----------------------------------------------\n" );

      getcwd(s, 200);  // gets current directory
      printf( "\nCurrent Directory: %s \n", s);

      d = opendir( "." ); // opens the current directory
      c = 0;
      printf("Directory:\n");
      // make sure we have directories in the current directory
      while ((de = readdir(d)))  // readdir reads the current directory
      {
        if ((de->d_type) & DT_DIR)
        printf( "\t   %d :  %s \n", c++, de->d_name); //displays the directory namelist
      }
      closedir( d ); // closes the current directory


      d = opendir( "." );
      c = 0;
      i=0;
      j=0;
      filessize=0;
      printf("File:");
      while ((de = readdir(d))){ /* READS the files in the current directory  */
        if (((de->d_type) & DT_REG)){
	         file_names[i]=de->d_name;  // saves the filre names in array so they ca n be used easily latter
	                     //printf( "\n \t   %d: %s", c++,de->d_name);
	                      i++;
                      }

                    }

                    for (x=0;x<i;x++)  // this for loops make sure the next and previous works properly and prints the filename accordingly
                    {
                      printf( "\n \t   %d: %s", x,file_names[x]);
	                     j++;
                       if (( j % 5 ) == 0 && j!=0 && (x+1)!=i ) {
	                        j=0;
	                         printf( "\n Hit N/n for Next or P/p for previous :");//separates the files into segments of 5 at a time
	                          do{
	                             k = getchar();getchar();
	                              if (k=='n'||k=='N'||k=='p'||k=='P')
		                              {
			                                 break;
		                                   }
		                                     printf("wrong input \n Hit N/n for Next or P/p for previous :");
	                                      }while(1);
                                        if (k=='p'||k=='P')
                                        {

                                          x--;
                                        }
                                      }

                                    }
                                    i=0,j=0,x=0;
                                    closedir( d );
	                                   printf( "\n-----------------------------------------\n" );


printf( "please enter \n\t d for Display\n\t e for Edit \n\t r for Run \n\t c for Change Directory \n\t s for Sort Directory listing \n\t q  Quit \n" );
c = getchar();

		  if(c=='d'){
		 printf( "Display which file?:" );/*if user picks d, will display a file that the user enters*/
			scanf( "%s", s );
			strcpy( cmd, "cat ");
			strcat( cmd, s );
			system( cmd );
                     }
		else if (c=='e'){  // if e is picked it lets us to edit the file . user enters the filename which he/she wants to edit
      // source class code
			printf( "Edit what?:" );
			scanf( "%s", s );
			strcpy( cmd, "pico ");
			strcat( cmd, s );
			system( cmd );


  	 	 }
		else if (c=='r')// runs the other program when you enter with e.g. ./program_name
    {
      // source class code
			printf( "Run what?:" );
                	scanf( "%s", cmd );
               	 	system( cmd );

		}
		else if (c=='q'){
			exit(0); // quit
		}
		else if (c=='c'){
			//sourde https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/
			printf( "Current working directory:" );

    			printf("%s\n", getcwd(s, 100));
          printf( "enter new working directory:\n" );
         scanf("%s", cmd);
         chdir(cmd);
  			  printf("New working directory%s\n", getcwd(s, 100));  // printing current new  working directory
  	 	 }

		else if (c=='s')

			/* statement for shorting
			source https://pubs.opengroup.org/onlinepubs/9699919799/functions/scandir.html */
			{
        struct dirent **namelist;
 			  int n;

  			 n = scandir(".", &namelist, 0, alphasort);
 				  if (n < 0)
   			    perror("scandir");
 				  else {
   			    while (n--) {
    			   printf("%s\n", namelist[n]->d_name);  // prints the file in decending
     			  free(namelist[n]);
      				 }
     			  free(namelist);
  			 }
			}
		else {
			printf("wrong input");

 			}

			printf( "\n-----------------------------------------\n" );
	getchar();

    }

}
