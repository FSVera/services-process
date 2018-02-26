#include "thread.h"

void bad_execute(int parameteres, char *program){
	if(parameteres < 2){
		printf("Usage => %s <num> <num> ... etc\n", program);
		exit(-1);
	}
}

int main(int argc, char **argv){

	const int THREADS = argc-1;
	bad_execute(argc, argv[0]);
	Value *value[THREADS];
	Thread **thread = new_thread(THREADS);

	for(int i=0; i<THREADS ; i++)
		value[i] = new_value(atoll(argv[i+1]));
	
	start_thread(thread, value, THREADS);

	for(int i=0; i<THREADS ; i++)
		printf("Thread %i:\n\
			id	==> %lu\n\
			value	==> %i\n\n",i+1, thread[i]->id, value[i]->output);
	

	return EXIT_SUCCESS;

}
