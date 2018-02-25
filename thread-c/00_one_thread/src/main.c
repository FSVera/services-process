#include "thread.h"

void check_execute(int parameteres, char **argv){
	if(parameteres < 2){
		printf("Usage => %s <num>\n", argv[0]);
		exit(-1);
	}
	user_value = atoll(argv[1]);
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
