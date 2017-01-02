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

  int* buff = (int*)malloc(sizeof(int));
  read( fd, buff, 4 ); // read 4 bytes from file tied to fd
  close(fd);
  return *buff;
}

void populateArray( int* arr ) {
 int c;
  for( c = 0; c < 10; c++ ) { //populate
    arr[c] = randInt();
  }
}

void printArray( int* arr ) {
  int c;
  for( c = 0; c < 10; c++ ) { //populate
    printf( "random %d: %d\n" , c , arr[c] );
  }
}

int main() {
  //printf( "%d\n" , randInt() );
  
  int* randVals; // array holding random values
  printf("%s\n\n", "Populating array..." );
  populateArray(randVals);
  
  //write array to file
  int wfd = open( "foo.txt", O_WRONLY | O_CREAT, 0666 ); // create and open hold
  
  if( wfd < 0 ) {  printf( "%s\n" , strerror(errno) ); }

  int w;
  w = write( wfd, randVals, sizeof(randVals) ); //write to hold from randVals
  if( w < 0 ) { printf( "%s\n" , strerror(errno) ); }
  
  close(wfd);

  //read from file to array
  int* newAry[10];
  int rfd = open( "foo.txt", O_RDONLY );
  if( rfd < 0 ) { printf( "%s\n" , strerror(errno) ); }
  w = read( rfd, newAry, sizeof(randVals) );
  if( w < 0 ) { printf( "%s\n" , strerror(errno) ); }
  close(rfd);

  printArray(randVals);
  printArray(newAry);
  
  return 0;
}
