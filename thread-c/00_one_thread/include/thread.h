#ifndef __THREAD_H__
#define __THREAD_H__

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct{
	pthread_t id;
	pthread_attr_t attr;
	void*(*fun_start)(void*);
}Thread;

int sum;
int user_value;

#ifdef __cplusplus
extern "C"{
#endif

	void *sum_runner(void*);
	void start_thread(Thread*);
	Thread *new_thread();

#ifdef __cplusplus
}
#endif


#endif
