/* Program to write to a new file, and display error if file already exist*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include <fcntl.h> 
#ifdef _WIN32
#include <io.h>
/* map POSIX names to MSVC names */
#define open  _open
#define write _write
#define close _close
#else
#include <unistd.h>
#endif


int main() 
{ 
  int sz; 
  char buf[100];

  strcpy(buf,"Sample file write");

  int fd = open("new_out2.txt", O_WRONLY  | O_CREAT | O_EXCL, 0774); 
  if (fd < 0) 
  { 
     perror("Error occured during open"); 
     exit(1); 
  } 
  printf("length of buf is (%d)",(int)strlen(buf));
  sz = write(fd, buf, strlen(buf)); 
  
  printf("\nwrite() returned  %d\n", sz); 
  
  close(fd); 
} 


