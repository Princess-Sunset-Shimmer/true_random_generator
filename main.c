#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <unistd.h>
#include <pthread.h>

void* head(void*);
void* tail(void*);

int8_t array[0x1];

char result_head[] = "go left\n";
char result_tail[] = "go right\n";

int main(void)
   {register int64_t go, write_head;
    pthread_t newthread[0x2];
    pthread_create(&newthread[0], NULL, &head, &array[0]);
    pthread_create(&newthread[0x1], NULL, &tail, &array[0]);
    write_head = 'h';
    go = true;
    ((int8_t*)array)[0] = go;
    pthread_join(newthread[0], NULL);
    pthread_join(newthread[0x1], NULL);
    go = ((uint8_t*)array)[0];
    if(go != write_head)goto print_tail;
    printf(&result_head[0]);
    goto finish_out;
print_tail:
    printf(&result_tail[0]);
finish_out:
    return 0; }

void* head(void* array)
   {register int64_t go;
ready:
    go = ((uint8_t*)array)[0];
    if(go == false)goto ready;
    go = 'h';
    ((int8_t*)array)[0] = go;
    return NULL; }

void* tail(void* array)
   {register int64_t go;
ready:
    go = ((uint8_t*)array)[0];
    if(go == false)goto ready;
    go = 't';
    ((int8_t*)array)[0] = go;
    return NULL; }




