#ifndef UTILS
#define UTILS

#include <string.h>
#include <assert.h>


char * strrepeat(char * key, int count) {

  assert( key != NULL );


  char * repeat = malloc(count);

  int j = 0;
  
  for ( int i = 0; i < count ; i++ ) {
    
    if ( key[i] == '\0' )
      i = 0;

    if ( strlen(repeat) == count )
      break;
    
    repeat[j++] = key[i];
  }

  return repeat;
}

int find(char alphabets[], char value) {
  
  for ( int i = 0; i <= 26; i++ ) {
    if ( alphabets[i] == value ) {
      return i + 1;
    }
  }
  
  return -1;
}

#endif
