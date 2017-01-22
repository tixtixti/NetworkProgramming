#include <stdio.h>
#include <time.h>
#include <unistd.h>

/*
* Prints process id, process parent id, and process group id.
*/
void printIds(){
  printf("\n");
  printf("my pID is: %d\n",getpid());
  printf("my parent pID is: %d\n",getppid());
  printf("my group ID is: %d\n",getpgrp());
  printf("\n");

}
/*
 * prints number of env variables and all of their content
 *
 */

void printEnv(int argc, char const *argv[]){
  printf("Printint enviroment variables \n");
  printf("I have %d variables\n", argc );
  for (int i = 0; i < argc; i++) {
    printf("%s\n",argv[i]);
  }
  printf("\n");
}

/*
 * Function to receive pointers to actual functions and calucates time it takes to
 * complete the method.
 * Trying to be modular and fancy but I quess I failed miserably.
 */
void measureTime( void(*fp)(), void(*fp2)(int,char const *[]), int argc, char const *argv[]){
    clock_t tic = clock();
    fp(argc,argv);
    clock_t toc = clock();
    clock_t tic2 = clock();
    fp2(argc,argv);
    clock_t toc2 = clock();
    printf("\n");
    printf("Time to run pID function in ms: %f\n",(double)(toc-tic) * 1000.0 / CLOCKS_PER_SEC);
    printf("Time to run env function in ms: %f\n",(double)(toc2-tic2) * 1000.0 / CLOCKS_PER_SEC);
    printf("\n");

}


int main(int argc, char const *argv[] ) {
  void (*fp)();
  void (*fp2)(int,char const *[]);
  fp2 = &printEnv;
  fp = &printIds;
  measureTime(fp,fp2,argc,argv);
  return 0;
}
