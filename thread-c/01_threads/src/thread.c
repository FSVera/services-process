#include "thread.h"

void start_thread(Thread **t, Value **v,int max){
	for(int i=0; i<max; i++)
		pthread_create(&t[i]->id, NULL, t[i]->fun_start, &v[i]->input);
	for(int i=0; i<max; i++)
		   pthread_join(t[i]->id, NULL);
}

void *sum_runner(void *arg){
	Value *v = (Value*)arg;
	for(int i=0; i<=v->input; i++)
		v->output += i;
	pthread_exit(0);	
}

Thread **new_thread(const int MAX){
	Thread **memory = NULL;
	memory = (Thread**)malloc(MAX * sizeof(Thread*));
	for(int i=0; i<MAX; i++){
		memory[i] = (Thread*)malloc(sizeof(Thread));
		memory[i]->fun_start = sum_runner;
		memory[i]->id = 0;
	}
	return memory;
}
