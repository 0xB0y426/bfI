#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void bfI(char *code) {
	unsigned char tape[1024] = {0}; // tape with 1024 bytes 
	int ptr = 0; 
	
	for(int i = 0; code[i] != '\0'; i++) { // if don't find the \0, continue the loop 
		char cmd = code[i];

		switch(cmd) {
			case '+':
				tape[ptr]++; // increase 1
				break;

			case '-':
				tape[ptr]--; // subtract 1
				break;

			case '<':
				if(ptr > 0) ptr--; // move to left
				break;

			case '>':
				if(ptr < 1023) ptr++; // move to right
				break;

			case '.':
				putchar(tape[ptr]); // print cel
				break;

			case ',':
				tape[ptr] = getchar(); // get input and took in tape
				break;

			case '[':
    				if (tape[ptr] == 0) {
        				int loop = 1;
        			while (loop > 0) {
            				i++;
            			if (code[i] == '[') loop++;
            			else if (code[i] == ']') loop--;
        			}
    			}
    			break;

			case ']':
    				if (tape[ptr] != 0) {
       	 				int loop = 1;
        				while (loop > 0) {
            					i--;
            					if (code[i] == ']') loop++;
            					else if (code[i] == '[') loop--;

        				}
					i--;
    				}
    				break;
		}
	}
}

int main(int argc, char **argv) {
	FILE *fp = fopen(argv[1], "rb");
	if(argc != 2) {
		printf("Brainfuck Interpreter v0.1\n By Magnetron\n\n Usage: bfI file.bf");
		exit(EXIT_FAILURE);
	}

	if (fp == NULL) {
    		perror("Brainfuck Error");
    		exit(EXIT_FAILURE);
  	}

	char line[256];
  	while(fgets(line, sizeof(line), fp) != NULL) {
  	 	char *code = line;
		bfI(code);
  	}

}
