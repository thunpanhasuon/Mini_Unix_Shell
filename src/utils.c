/* I don't know why i write this code maybe it just for personal if there more feature thatit want to add */
#pragma once

#include <asm-generic/ioctls.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int get_terminal_width() {
	struct winsize ws; 

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
		perror("ioctl erorr");
		return 80;  /* for standerd */ 
	}
	return ws.ws_col; 
}

void print_centered(const char* text) {
	int text_lenght = strlen(text);
	int terminal_width = get_terminal_width();
	int padding = (terminal_width - text_lenght) / 2;

	if (text_lenght >= terminal_width) {
		printf("%s\n", text); 
	}

	for (int i = 0; i < padding; i++) {
		printf(" "); 
	}
	printf("%s\n", text);
}	
