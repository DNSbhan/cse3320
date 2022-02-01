/*
Dinesh Bhandari
1001802374
Assignment 1
David Levine
CSE 3320-001
Major Source file: file provided by profeser at class myshell.c
i have used the help from below links for this Assignment
 other sources:
 /* statement for sorting
 source https://pubs.opengroup.org/onlinepubs/9699919799/functions/scandir.html */

 //source https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/

*/

-----------------------------------------------------------------------------------------------------
I run the program both in  pi and mac -terminal.

step 1: compile the program gcc Bhandari_2374.c
step 2: Run the output file ./a.output
step 3:
        the program prints the directory name that are on the current working Directory
        the program prints the files name that are in a file but
          only 5 file name at a time.
          it promotes for enter n/N for next or p/P (if we enter anything else then it gives wrong input and force you to enter only those n/N or p/P)
          gives the right output
step 4: ask you for selection what you want to do
            d for Display
            e for Edit
            r for Run
            c for Change Directory
            s for Sort Directory listing
            q  Quit
      when you select d it displays the content in terminal,
      edit lets you to edit the current file
      run can run the other program
      c lets you to change current Directory to the Directory you want to change
      sort sorts the filename according to file name
      q quits the program
  if you enter anything else it promotes wrong input and got to step 3

-------------------------------------------------------------------------------------------------
Sample output :
-------------------------------------------------------------------------------------------------
dineshbhandari@dineshs-MacBook-Pro cse 3320 % gcc Bhandari_2374.c
dineshbhandari@dineshs-MacBook-Pro cse 3320 % ./a.out

Time: Mon Jun 14 14:08:24 2021

-----------------------------------------------

Current Directory: /Users/dineshbhandari/Desktop/cse 3320
Directory:
	   0 :  .
	   1 :  ..
File:
 	   0: CSE 3310 Term Project - Summer 2021.docx
 	   1: .DS_Store
 	   2: bhandari.docx
 	   3: Deep.pdf
 	   4: CSE 3310 Term Project - Summer 2021 (1).docx
 Hit N/n for Next or P/p for previous :n

 	   5: group4.docx
 	   6: Bhandari_2374.c
 	   7: Dinesh Bhandari.pdf
 	   8: Assignment1 (1).doc
 	   9: Assignment1.doc
 Hit N/n for Next or P/p for previous :p

 	   9: Assignment1.doc
 	   10: a.out
 	   11: Readme.txt
-----------------------------------------
please enter
	 d for Display
	 e for Edit
	 r for Run
	 c for Change Directory
	 s for Sort Directory listing
	 q  Quit
q
dineshbhandari@dineshs-MacBook-Pro cse 3320 %
