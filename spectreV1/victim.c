#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

char* secret = "Test shared memory-based attack.";

int main() {
    int shm_fd = shm_open("/shared_memory", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }
    size_t secret_size = strlen(secret) + 1;
    if (ftruncate(shm_fd, secret_size) == -1) {
        perror("ftruncate");
        return 1;
    }
    void* shared_memory = mmap(NULL, secret_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    close(shm_fd);
    memcpy(shared_memory, secret, secret_size);
    printf("Putting '%s' in memory, address %p\n", (char*)shared_memory, shared_memory);
    getchar();
    munmap(shared_memory, secret_size);
    return 0;
}
