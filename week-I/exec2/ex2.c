#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
/*
 * Read file line by line and print each line twice. ex2-a
 */
void douplerStdlib(const char* filename){
  FILE* file =fopen(filename,"r");
  char line[256];
  while(fgets(line,sizeof(line),file)){
    printf("%s",line );
    printf("%s",line );
  }
  fclose(file);
}

/*
 * This compiles, and prints read files twice, but ...
 * it does not really work. Too late to fix, maybe after other excercises. 
 */
void douplerSystemCalls(const char* filename){
  //open file
  int fd = open(filename,O_RDONLY);
  char data[1024];
  //read it to buffer
  read(fd,data,1024);
  char * pch;
  pch = strtok(data,"\n");
  while(pch !=NULL){
    write(1, pch, sizeof(pch));
    write(1, pch, sizeof(pch));
    write(1,"\n",sizeof("\n"));
    pch = "";
    pch = strtok(NULL, "\n");
  }
  //close file.
  close(fd);

}
/*
 * read env from certain postion.
 */
const char* readArgv(char const *argv[], int pos){
  return argv[pos];
}
/*
 * read max 20 char input from stdin and return it.
 */
char* readInput(){
  static char input[20];
  scanf("%s",input);
  return input;
}


int main(int argc, char const *argv[]) {
  if(argc == 1){
    douplerSystemCalls(readInput());
  } else {
    douplerSystemCalls(readArgv(argv,1));
  }

  return 0;
}
