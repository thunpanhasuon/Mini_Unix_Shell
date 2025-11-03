#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

/* my own header */
#include "utils.c" 

#define MAX_CHARACTER 50
#define MAX_ARGUMENT_VECTOR 10

void init_shell() {
	print_centered("welcome to Clamy");
} 

int exec_parsed(char* parse, char* argv[]) {
	pid_t pid; 

	pid = fork(); 

	if (pid < 0) {
		perror("Fork failded"); 
		exit(EXIT_FAILURE); /* exit failure is map to 1 failure 0 for success */
	}
	if (pid == 0) {
		execvp(parse, argv);

		perror("vorp failure");
		exit(EXIT_FAILURE);
	} else {
		wait(NULL);
	}

	return EXIT_SUCCESS; 
} 
int parsed(char* buffers, char* argv[], int maxSize) {
	const char delimiter[] = " "; 
	char* token; 

	token = strtok(buffers, delimiter);

	int index = 0; 

	while (token != NULL) {

		argv[index] = token; 
		token = strtok(NULL, delimiter);

		index++; 
	}
	argv[index] = NULL; 

	return 0; 
}
int main() {
	char buffers[MAX_CHARACTER]; 
	char* argv[MAX_ARGUMENT_VECTOR];
	
	init_shell();

        bool exit = false;			
	while (!exit) {
		printf(">");
		if (fgets(buffers, sizeof(buffers), stdin) != NULL) {
			
			size_t lens = strlen(buffers); 
			if (lens > 0 && buffers[lens - 1] == '\n') {
				buffers[lens - 1] = '\0';
			}

			if (strcmp(buffers, "exit") == 0) {
				printf("Good bye User :) \n");
				exit = true; 
			}
			if (parsed(buffers, argv, MAX_ARGUMENT_VECTOR) == 0) {
				printf("parse succesfully\n");
			};

			if (exec_parsed(buffers, argv) == 0) {
				printf("exec successfully\n");
			};

		} else {
			printf("invaid input\n");
		}

	}
	return 0;
}
