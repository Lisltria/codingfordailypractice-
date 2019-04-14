#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t semA;
sem_t semB;
sem_t semC;

void *funA(void *arg){
	int id;
	id = *((int *)arg);
	while(1){
		sem_wait(&semA);
		cout << "id is " << id <<endl;
		sem_post(&semB);
		usleep(1000000);
	}
	pthread_exit(NULL);
}

void *funB(void *arg){
	int id;
	id = *((int *)arg);
	while(1){
		sem_wait(&semB);
		cout << "id is " << id <<endl;
		sem_post(&semC);
		usleep(1000000);
	}
	pthread_exit(NULL);
}

void *funC(void *arg){
	int id;
	id = *((int *)arg);
	while(1){
		sem_wait(&semC);
		cout << "id is " << id <<endl;
		sem_post(&semA);
		usleep(1000000);
	}
	pthread_exit(NULL);
}

int main() {
	int n1 = 1, n2 = 2, n3 = 3;
	pthread_t threadA;
	pthread_t threadB;
	pthread_t threadC;
	pthread_attr_t attr;
	sem_init(&semA, 0, 1);
	sem_init(&semB, 0, 0);
	sem_init(&semC, 0, 0);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	pthread_create(&threadA,&attr,funA,(void *)(&n1));

	pthread_create(&threadB,&attr,funB,(void *)(&n2));
	pthread_create(&threadC,&attr,funC,(void *)(&n3));

	while(1){}

	return 0;
}
