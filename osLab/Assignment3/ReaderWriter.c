// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>

// #define MAX_READERS 5

// int shared_data = 0;
// int readers_count = 0;
// sem_t mutex, wrt, readTry;

// void* writer(void* arg) {
//     while (1) {
//         sem_wait(&wrt);

//         // Writing to the shared resource
//         shared_data++;
//         printf("Writer writes: %d\n", shared_data);

//         sem_post(&wrt);

//         // Simulate some time for writing
//         sleep(2);
//     }

//     pthread_exit(NULL);
// }

// void* reader(void* arg) {
//     while (1) {
//         sem_wait(&readTry);
//         sem_wait(&mutex);

//         readers_count++;
//         if (readers_count == 1) {
//             sem_wait(&wrt);
//         }

//         sem_post(&mutex);
//         sem_post(&readTry);

//         // Reading from the shared resource
//         printf("Reader reads: %d\n", shared_data);

//         sem_wait(&mutex);
//         readers_count--;
//         if (readers_count == 0) {
//             sem_post(&wrt);
//         }
//         sem_post(&mutex);

//         // Simulate some time for reading
//         sleep(1);
//     }

//     pthread_exit(NULL);
// }

// int main() {
//     // Initialize semaphores
//     sem_init(&mutex, 0, 1);
//     sem_init(&wrt, 0, 1);
//     sem_init(&readTry, 0, 1);

//     // Create writer and reader threads
//     pthread_t writer_thread, reader_threads[MAX_READERS];
//     pthread_create(&writer_thread, NULL, writer, NULL);
    
//     for (int i = 0; i < MAX_READERS; i++) {
//         pthread_create(&reader_threads[i], NULL, reader, NULL);
//     }

//     // Wait for threads to finish (this will never happen in this example)
//     pthread_join(writer_thread, NULL);
//     for (int i = 0; i < MAX_READERS; i++) {
//         pthread_join(reader_threads[i], NULL);
//     }

//     // Destroy semaphores
//     sem_destroy(&mutex);
//     sem_destroy(&wrt);
//     sem_destroy(&readTry);

//     return 0;
// }