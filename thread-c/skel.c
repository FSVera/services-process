#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *function(){
	printf("...\n");
	pthread_exit(0);
}

int main(){

	pthread_t id;
	pthread_create(&id, NULL, function, NULL);
	pthread_join(id, NULL);

	return EXIT_SUCCESS;

}
