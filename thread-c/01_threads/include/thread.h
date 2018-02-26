#ifndef __THREAD_H__
#define __THREAD_H__

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct{
	pthread_t id;
	void*(*fun_start)(void*);
}Thread;

typedef struct{
	int input;
	int output;
}Value;


#ifdef __cplusplus
extern "C"{
#endif

	void *sum_runner(void*);
	void start_thread(Thread**,Value**,int);
	Thread **new_thread(int);
	Value *new_value(int a);

#ifdef __cplusplus
}
#endif


#endif
