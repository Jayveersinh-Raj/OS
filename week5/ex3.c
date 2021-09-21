#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct {
    int count;
    int capacity;
    int *fruits;
} basket;

void* producer()
{
    while(1)
    {
        while(basket.count >= basket.capacity);

        // if race condition happens, stop everything
        if(basket.count >= basket.capacity)
        {
            printf("Error: Attempt to produce to a full buffer");
            exit(1);
        }

        // insert
        basket.fruits[basket.count] = basket.count;
        basket.count++;
    }
}
void* consumer()
{
    while(1)
    {
        // basket is empty. Wait
        while(basket.count <= 0);

        // if race condition happens, stop everything
        if(basket.count <= 0)
        {
            printf("Error: Attempt to consume from an empty buffer");
            exit(1);
        }

        // Use fruit
        basket.fruits[basket.count] = 0;
        basket.count--;
    }
}

int main()
{
    basket.capacity = 9;
    basket.count = 0;
    basket.fruits = (int*) malloc(basket.capacity * sizeof(int));

    pthread_t producer, consumer;

    pthread_create(&producer, NULL,(void*)producer, NULL);
    pthread_create(&consumer, NULL,(void*)consumer, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    return 0;
}
