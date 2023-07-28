#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int
lookup_host (const char *host)
{
  struct addrinfo hints, *res, *result;
  int errcode;
  char addrstr[100];
  void *ptr;

  memset (&hints, 0, sizeof (hints));
  hints.ai_family = PF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags |= AI_CANONNAME;

  errcode = getaddrinfo (host, NULL, &hints, &result);
  if (errcode != 0)
    {
      perror ("getaddrinfo");
      return -1;
    }
  
  res = result;

  printf ("Host: %s\n", host);
  while (res)
    {
      inet_ntop (res->ai_family, res->ai_addr->sa_data, addrstr, 100);

      switch (res->ai_family)
        {
        case AF_INET:
          ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
          break;
        case AF_INET6:
          ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
          break;
        }
      inet_ntop (res->ai_family, ptr, addrstr, 100);
      printf ("IPv%d address: %s (%s)\n", res->ai_family == PF_INET6 ? 6 : 4,
              addrstr, res->ai_canonname);
      res = res->ai_next;
    }
  
  freeaddrinfo(result);

  return 0;
}

int main (void)
{
  char inbuf[256];
  int len;
  do {
    bzero(inbuf, 256);
    printf("Type domain name:\n");
    fgets(inbuf, 256, stdin);
    len = strlen(inbuf);
    inbuf[len-1] = '\0';
    if(strlen(inbuf) > 0)
      lookup_host (inbuf);
    else
      return EXIT_SUCCESS;
  } while(1);
}