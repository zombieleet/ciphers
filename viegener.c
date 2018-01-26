#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#include "alpha.h"


#define FREE(p) { \
    free((p));    \
    p = NULL;     \
  }

/**
   the key is duplicated to match the length of the message ( plain text )
   you encrypt by adding the key to the plain text module 26
   if the value is greater than 26 , restart
 **/


char * viegener(char * key, char * message) {
  
  size_t key_message_size = strlen(key);

  char * cipher_text = malloc(sizeof(key));
  
  for ( int i = 0; i < key_message_size; i++ ) {
    
    char key_value = toupper(key[i]);
    char message_value = toupper(message[i]);
    
    int key_index = find(CHARACTERS, key_value);
    int message_index = find(CHARACTERS, message_value);

    int cipher_text_index = ( key_index +  message_index ) % 26;
    
    cipher_text[i] = CHARACTERS[cipher_text_index] > 26 ? CHARACTERS[cipher_text_index] : CHARACTERS[0];
    
  }

  return cipher_text;
  
}

int main(int argc, char * argv[]) {

  if ( argc != 3 ) {
    fprintf(stderr, "Insufficient number of argument");
    return 1;
  }
  
  char * key = argv[1];
  char * message = argv[2];

  char * cipher_text = NULL;

  if ( strlen(key) != strlen(message) ) {
    key = strrepeat(key, strlen(message));
    cipher_text = viegener(key,message);
    printf("%s\n", cipher_text);
    FREE(key);
    FREE(cipher_text);
    return 0;
  }
  
  cipher_text = viegener(key,message);
  printf("%s\n", cipher_text);
  FREE(cipher_text);
  return 0;
}

