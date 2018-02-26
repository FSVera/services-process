#include "thread.h"

Value *new_value(int input){
	Value *memory = (Value*)malloc(sizeof(Value));
		memory->input = input;
	return memory;
}
