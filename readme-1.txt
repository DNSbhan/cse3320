/* dinesh Bhandari
//cse 3320
//Assignment 3
sources: 
https://www.quora.com/In-C-how-does-one-code-a-file-system-for-an-OS
https://opensource.com/article/19/4/create-filesystem-linux-partition
https://www.geeksforgeeks.org/create-directoryfolder-cc-program/
https://study.com/academy/lesson/creating-managing-filesystems-in-linux.html

*/

----------------------------------------------------------------------------

Currently my filesystem works for initialization of file system, creating directory inside file system, changing path on it and removing directory 


my sample output: 



dany@dany-VirtualBox:~/Desktop/filesystem$ gcc filesystemunix.c 
filesystemunix.c: In function ‘cpin’:
filesystemunix.c:488:37: warning: format ‘%i’ expects argument of type ‘int’, but argument 2 has type ‘size_t’ {aka ‘long unsigned int’} [-Wformat=]
  488 |             printf("Current length %i", strlen(strrchr(dstpath,'/')));
      |                                    ~^   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                                     |   |
      |                                     int size_t {aka long unsigned int}
      |                                    %li
filesystemunix.c:495:37: warning: format ‘%i’ expects argument of type ‘int’, but argument 2 has type ‘char *’ [-Wformat=]
  495 |             printf("Current length %i", dstpath);
      |                                    ~^   ~~~~~~~
      |                                     |   |
      |                                     int char *
      |                                    %s
dany@dany-VirtualBox:~/Desktop/filesystem$ ./a.out
Enter command:

Dinesh@fileSystem ./$initfs dinesh 6064 64
The file system is initialized
Dinesh@fileSystem ./$initfs dinesh 2345 64
File system already initalized
Dinesh@fileSystem ./$ls
.
..

Dinesh@fileSystem ./$mkdir assignment3
Dinesh@fileSystem ./$mkdir assignment2 

Dinesh@fileSystem ./$ls
.
..
assignment3
assignment2

Dinesh@fileSystem ./$em assignment2
Invalid command provided
Dinesh@fileSystem ./$rm assignment2 

Dinesh@fileSystem ./$ls
.
..
assignment3

Dinesh@fileSystem ./$cd assignment3

Dinesh@fileSystem ./assignment3 $cat ram
File does not exist ram

Dinesh@fileSystem ./assignment3 $q
dany@dany-VirtualBox:~/Desktop/filesystem$ 


