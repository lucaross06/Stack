
#include <stdio.h>
#include <stdlib.h>

struct stack{
	char top;
	int length;
	char arr[];
};

void push(struct stack* stack, char c ){
	stack = realloc(stack,sizeof(stack) + sizeof(c));
	stack -> arr[stack -> length++] = c;
	stack -> top = c;
}

void pop(struct stack* stack){
	stack = realloc(stack, sizeof(stack) - sizeof(char));
	stack -> length--;
	stack -> top = stack -> arr[stack -> length - 1];
}

void printTop(struct stack* stack){
	printf("The top char is: %c\n", stack -> top);
}

void printLength(struct stack* stack){
	printf("The length of the stack is: %d\n", stack -> length);
}

void printStack(struct stack* stack){
	for(int i = 0; i < stack -> length; i++){
		printf("The item number %d in the stack is: %c\n", i , stack -> arr[i]);
	}
}

char *inputString(FILE* fp, size_t size, size_t* ret){
//The size is extended by the input with the value of the provisional
	char *str;
	int ch;
	size_t len = 0; 
	str = realloc(NULL, sizeof(*str)*size);//size is start size
	if(!str)return str;
	while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
		str[len++]=ch;
		if(len==size){
			str = realloc(str, sizeof(*str)*(size+=16));
			if(!str)return str;
		}
	}

	*ret = len;
	str[len++]='\0';

	return realloc(str, sizeof(*str)*len);
}

int main(int argc, char **argv){
	char *m;
	char command[4];
	size_t* len;
	len = realloc(NULL,sizeof(size_t));
	printf("input string : ");
	m = inputString(stdin, 10, len);
	printf("%s\n", m);
	printf("%d\n",*len);

	struct stack *stNum = malloc(sizeof(struct stack) + *len * sizeof(char));

	for(int i = 0; i < *len; i++){
		stNum -> arr[i] = m[i];
//		printf("%c", stNum -> arr[i]);
	}
	stNum -> top = stNum -> arr[*len -1];
	stNum -> length = *len;
	push(stNum,'a');
	printTop(stNum);
	printLength(stNum);
	printStack(stNum);
	pop(stNum);
	printStack(stNum);
	while(fgets(command,sizeof(command),stdin)){
		if(strcmp(command == "add")){
			
		}
	}

	free(m);
	return 0;
}
