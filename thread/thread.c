#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
pthread_t tid[2];

sem_t mutex;
char* ret;

struct mystruct {
    char* name;
};
void* doSomething(void *arg)
{
    struct mystruct s = *((struct mystruct*) (arg));
    unsigned long i = 0;
    pthread_t id = pthread_self();
    printf("%s\n", s.name);
    if (strcmp(s.name,"Hello")) {
        sem_wait(&mutex);
        ret = "My World";
        pthread_exit(&ret);
    }
    if (strcmp(s.name,"World")) {
        sem_wait(&mutex);
        ret = "of Mine";
        pthread_exit(&ret);
    }
/*
    if (pthread_equal(id, tid[0])) {
        printf("%s\n", "First");
    } else {
        printf("%s\n", "Second");
    }
*/    
    for (i=0; i< (0xFFFFFFFF); i++);
    return NULL;

}

int main (int argc, char* argv[]) {
    int i = 0;
    int err;
    char** value;
    char** value2;
    struct mystruct s[2];

    sem_init(&mutex, 0, 1);
    s[0].name = "Hello";
    s[1].name = "World";
    while (i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomething, &(s[i]));
        if (err != 0)
            printf("Error : %s\n", strerror(err));
        else
            printf("Success\n");
        i++;

    }

    pthread_join(tid[0], (void**) &value);
    printf("%s\n",*value);
    sem_post(&mutex);
    pthread_join(tid[1], (void**) &value2);
    printf("%s\n",*value2);
    sem_post(&mutex);
    return 0;
}
