
#include <stdio.h>
#include <poll.h>

int main() {
    FILE* file = fopen("a.txt", "r");
	int TIMEOUT = -1;
    if (file == NULL) {
        perror("Dosya açılamadı");
        return -1;
    }

    int filefd = fileno(file);

    struct pollfd fds[1];
    fds[0].fd = filefd;
    fds[0].events = POLLIN; // Okuma olayını izle

    int result = poll(fds, 1, TIMEOUT); // 1 dosya tanımlayıcısını izle, TIMEOUT zaman aşımı süresi

    if (result == -1) {
        perror("poll failed");
        return -1;
    }

    if (fds[0].revents & POLLIN) {
		char buffer[256];
    	while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
    }
        printf("a.txt dosyasında okuma olayı gerçekleşti.\n");
    }

    fclose(file);

    return 0;
}
