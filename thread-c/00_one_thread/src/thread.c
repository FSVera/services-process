#include "thread.h"

void start_thread(Thread *t){
	pthread_attr_init(&t->attr);
	pthread_create(&t->id, &t->attr, t->fun_start, &user_value);
	pthread_join(t->id, NULL);
}

void *sum_runner(void *arg){
	for(int i=0; i<=*(int*)arg; i++)
		sum += i;
	pthread_exit(0);	
}

Thread *new_thread(){
	Thread *memory = (Thread*)malloc(sizeof(Thread));
		   memory->fun_start = sum_runner;
	return memory;
}
