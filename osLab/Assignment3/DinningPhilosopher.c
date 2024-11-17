// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>

// #define N 5 // Number of philosophers

// pthread_mutex_t mutex;
// sem_t chopsticks[N];

// void *philosopher(void *arg) {
//     int id = *((int *)arg);
//     int left_chopstick = id;
//     int right_chopstick = (id + 1) % N;

//     while (1) {
//         // Think
//         printf("Philosopher %d is thinking\n", id);
//         sleep(rand() % 3 + 1);

//         // Pick up chopsticks
//         printf("Philosopher %d is hungry and trying to pick up chopsticks\n", id);
//         pthread_mutex_lock(&mutex);
//         sem_wait(&chopsticks[left_chopstick]);
//         sem_wait(&chopsticks[right_chopstick]);
//         pthread_mutex_unlock(&mutex);

//         // Eat
//         printf("Philosopher %d is eating\n", id);
//         sleep(rand() % 3 + 1);

//         // Put down chopsticks
//         printf("Philosopher %d finished eating and putting down chopsticks\n", id);
//         sem_post(&chopsticks[left_chopstick]);
//         sem_post(&chopsticks[right_chopstick]);
//     }
// }

// int main() {
//     pthread_t philosophers[N];
//     int philosopher_ids[N];

//     pthread_mutex_init(&mutex, NULL);

//     for (int i = 0; i < N; i++) {
//         sem_init(&chopsticks[i], 0, 1);
//     }

//     for (int i = 0; i < N; i++) {
//         philosopher_ids[i] = i;
//         pthread_create(&philosophers[i], NULL, philosopher, (void *)&philosopher_ids[i]);
//     }

//     for (int i = 0; i < N; i++) {
//         pthread_join(philosophers[i], NULL);
//     }

//     pthread_mutex_destroy(&mutex);

//     for (int i = 0; i < N; i++) {
//         sem_destroy(&chopsticks[i]);
//     }

//     return 0;
// }