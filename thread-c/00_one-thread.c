#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct{
	pthread_t id;
	pthread_attr_t attr;
	void*(*fun_start)(void*);
}Thread;

int sum = 0;
int user_value = 0;

void *sum_runner(void *arg){
	for(int i=0; i<=*(int*)arg; i++)
		sum += i;
	pthread_exit(0);	
}

void check_execute(int parameteres, char **argv){
	if(parameteres < 2){
		printf("Usage => %s <num>\n", argv[0]);
		exit(-1);
	}
	user_value = atoll(argv[1]);
}

Thread *new_thread(){
	Thread *memory = (Thread*)malloc(sizeof(Thread));
		   memory->fun_start = sum_runner;
	return memory;
}

void start_thread(Thread *t){
	pthread_attr_init(&t->attr);
	pthread_create(&t->id, &t->attr, t->fun_start, &user_value);
	pthread_join(t->id, NULL);
}

int main(int argc, char **argv){

	check_execute(argc, argv);

	Thread *thread = new_thread();
	start_thread(thread);

	printf("First thread\n\
		id	==> %lu\n\
		value	==> %i\n",thread->id, sum);

	return EXIT_SUCCESS;

}
