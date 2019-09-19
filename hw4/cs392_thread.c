// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int item1_counter = 0;
int item2_counter = 0;
int item3_counter = 0;
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;

void *cs392_thread_run(void *arg){
	FILE* fp;
	fp = fopen(arg, "r");
	char str[8];
	
	while(fgets(str, sizeof(str), fp)!= NULL){
		if(strcmp(str, "+item1\n") ==0){
			pthread_mutex_lock(&lock1);
			item1_counter++;
			pthread_mutex_unlock(&lock1);
		}
		if(strcmp(str, "-item1\n") ==0){
			pthread_mutex_lock(&lock1);
			item1_counter--;
			pthread_mutex_unlock(&lock1);
		}
		if(strcmp(str, "+item2\n") ==0){
			pthread_mutex_lock(&lock2);
			item2_counter++;
			pthread_mutex_unlock(&lock2);
		}
		if(strcmp(str, "-item2\n") ==0){
			pthread_mutex_lock(&lock2);
			item2_counter--;
			pthread_mutex_unlock(&lock2);
		}
		if(strcmp(str, "+item3\n") ==0){
			pthread_mutex_lock(&lock3);
			item3_counter++;
			pthread_mutex_unlock(&lock3);
		}
		if(strcmp(str, "-item3\n") ==0){
			pthread_mutex_lock(&lock3);
			item3_counter--;
			pthread_mutex_unlock(&lock3);
		}
	}
	fclose(fp);
	pthread_exit(NULL);
	return NULL;
	
}

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Incorrect number of inputs.\n");
		return 1;
	}else{
		pthread_t thread1, thread2, thread3;
		if(pthread_mutex_init(&lock1, NULL) != 0){
			printf("Mutex init has failed\n");
			return 1;
		}
		if(pthread_mutex_init(&lock2, NULL) != 0){
			printf("Mutex init has failed\n");
			return 1;
		}
		if(pthread_mutex_init(&lock3, NULL) != 0){
			printf("Mutex init has failed\n");
			return 1;
		}
		pthread_create(&thread1, NULL, cs392_thread_run, (void*)argv[1]);
		pthread_create(&thread2, NULL, cs392_thread_run, (void*)argv[2]);
		pthread_create(&thread3, NULL, cs392_thread_run, (void*)argv[3]);
		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);
		pthread_join(thread3, NULL);
		pthread_mutex_destroy(&lock1);
		pthread_mutex_destroy(&lock2);
		pthread_mutex_destroy(&lock3);
		printf("The final value of item1_counter, item2_counter, and item3_counter are %d, %d, and %d", item1_counter, item2_counter, item3_counter);
		printf("\n");
	}
	


}