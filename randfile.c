#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int randInt() {
  int fd = open( "/dev/random" , O_RDONLY );
  if( fd < 0 ) {
    printf( "%s\n" , strerror(errno) );
    exit(1);
  }

  unsigned int* buff = (int*)malloc(sizeof(int));
  read( fd, buff, 4 ); // read 4 bytes from file tied to fd
  close(fd);
  return buff;
}

void printArray( int* arr ) {
  int c;
  for( c = 0; c < 10; c++ ) {
    printf( "random %d: %d\n" , c , arr[c] );
  }
  printf( "\n" );
}

int* populateArray() {
  int* arr[10];
  int c;
  for( c = 0; c < 10; c++ ) {
    arr[c] = randInt();
  }
  return arr;
}

int main() {
  //printf( "%d\n" , randInt() );
  
  int* randVals; // array holding random values
  printf("%s\n\n", "Populating array..." );
  randVals = populateArray(); 

  //write array to file
  int wfd = open( "foo.txt", O_WRONLY | O_CREAT, 0666 ); // create and open hold

   if( wfd < 0 ) { //check
    printf( "%s\n" , strerror(errno) );
    exit(1);
  }
  write( wfd, randVals, sizeof(randVals) ); //write to hold from randVals*/
  close(wfd);

  //read from file to array
  int* newAry[10];
  int rfd = open( "foo.txt", O_RDONLY );
  if( rfd < 0 ) { //check
    printf( "%s\n" , strerror(errno) );
    exit(1);
  }
  
  read( rfd, newAry, sizeof(randVals) );
  close(rfd);
  
  printArray(randVals);  
  printArray(newAry);

  return 0;
}
