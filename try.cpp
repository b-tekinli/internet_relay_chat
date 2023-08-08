#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
	struct addrinfo hints, *res;
	int status;
	char ip_address[INET6_ADDRSTRLEN];
	char hostname[NI_MAXHOST];

	// Set up the hints structure
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;	// IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP socket

	// Replace "127.0.0.1" with the IP address you want to look up
	const char *ip_to_lookup = "facebook.com";

	// Get address information
	if ((status = getaddrinfo(ip_to_lookup, NULL, &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 1;
	}

	// Convert the IP address to a printable string
	void *addr;
	if (res->ai_family == AF_INET) {
		struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
		addr = &(ipv4->sin_addr);
	} else {
		struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)res->ai_addr;
		addr = &(ipv6->sin6_addr);
	}
	
	char *address = inet_ntoa(*((struct in_addr *)addr));
	printf("Adress: %s\n",address);

	freeaddrinfo(res); // Free the address info structure

	return 0;
}

//#include <stdio.h>
//#include <unistd.h>

//int main() {
//	char hostname[256];

//	if (gethostname(hostname, sizeof(hostname)) == 0) {
//		printf("Hostname: %s\n", hostname);
//	} else {
//		perror("gethostname");
//		return 1;
//	}

//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <netdb.h>

//int main() {
//	struct addrinfo hints, *info;
//	char hostname[256];

//	memset(&hints, 0, sizeof hints);
//	hints.ai_family = AF_UNSPEC;  // IPv4 or IPv6
//	hints.ai_socktype = SOCK_STREAM;

//	if (getaddrinfo("localhost", NULL, &hints, &info) != 0) {
//		perror("getaddrinfo");
//		return 1;
//	}

//	getnameinfo(info->ai_addr, info->ai_addrlen, hostname, sizeof(hostname), NULL, 0, NI_NAMEREQD);
//	printf("Hostname: %s\n", hostname);

//	freeaddrinfo(info);
//	return 0;
//}
