#include "pipe_networking.h"

static void sighandler(int signo){
  if (signo == SIGINT){
    remove("wkp");
    exit(1);
  }
}

int main() {

  int to_client;
  int from_client;

  char str[BUFFER_SIZE];

  signal(SIGINT, sighandler);

  while (1){

    from_client = server_handshake( &to_client );

    while ( read(from_client, str, sizeof(str)) ){
      printf("Message Received: %s", str);
      char* dummy = str;
      while (*dummy){
	       *dummy += 5;
	        dummy ++;
      }
      printf("Message Sent: %s\n", str);
      write(to_client, str, sizeof(str));

    }
  }

  return 0;
}
