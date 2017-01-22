#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
/*
 * read env from certain postion.
 */
const char* readArgv(char const *argv[], int pos){
  return argv[pos];
}

/*
 * open and return fd to spesific file
 */
int fileOpener(const char* filename){
  return open(filename,O_RDONLY);
}

/*
 * print first 12 bytes of file.
 */
void printer(int fd){
  char buffer[12];
  read(fd,buffer, 12);
  write(1,buffer,12);
}
/*
 * handle given signal.   
 */
void sigHandler(int signum){
  printf("\n");
  printf("%s\n","received CTRL + C" );
  printf("\n");
  exit(signum);
}

int main(int argc, char const *argv[]) {
  signal(SIGINT, sigHandler);
  while(1)
  {
    printer( fileOpener ( readArgv(argv, 1) ));
  }
  return EXIT_SUCCESS;
}
