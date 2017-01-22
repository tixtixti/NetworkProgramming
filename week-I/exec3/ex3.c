#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  /*
   * open file, get its fd and then call fstat for it.
   * print answers. 
   */
  struct stat sb;
  int fd = open("ex3.txt",O_RDONLY);
  fstat(fd, &sb);
  printf("\towner: %u \n", sb.st_uid);
  printf("\tmode: %o\n", sb.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
  printf("\tsize: %lld\n", sb.st_size);

  printf("\n");


  return 0;
}
