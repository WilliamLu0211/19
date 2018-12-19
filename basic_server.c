#include "pipe_networking.h"

int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char str[BUFFER_SIZE];

  while (1){

    read(from_client, str, sizeof(str));
    printf("Message Received: %s\n", str);
    char* dummy = str;
    while (*dummy){
      *dummy += 5;
      dummy ++;
    }
    write(to_client, str, sizeof(str));
    
  }
}
