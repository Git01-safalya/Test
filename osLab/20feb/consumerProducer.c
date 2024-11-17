
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t mutex, empty, full;

void produce(int item) {
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
}

int consume() {
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    return item;
}

void* producer(void* arg) {
    int produced_item = 1;

    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);

        produce(produced_item);
        printf("Produced: %d\n", produced_item++);

        sem_post(&mutex);
        sem_post(&full);

        // Simulate some time for producing
        sleep(1);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        int consumed_item = consume();
        printf("Consumed: %d\n", consumed_item);

        sem_post(&mutex);
        sem_post(&empty);

        // Simulate some time for consuming
        sleep(2);
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish (this will never happen in this example)
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}