//    PROGRAM-ID. yessviz
//        AUTHOR. Rev. Taylor R. Rainwater
// LAST-REVISION. 2017-09-21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

#define CHARBYTES 1

/**
 * input_string
 * args: 
 * none
 * return:
 * char pointer
 * description: 
 * When called, takes input from stdin
 * char for char until the use types 
 * a newline or the function reaches an EOF
 * then it returns a pointer to the string. 
 * Make sure to free the returned pointer
 * when finished. 
 */
char *input_string()
{	char c;
	char *str;
	int i = 0;

	str = malloc(CHARBYTES);
	while((c = getchar()) != '\n' && c != EOF){
		str[i++] = c;
		str = realloc(str, i+1);
	}
	str[i] = '\0';

	return str;
}

int main()
{	char *input;

	printf("ye: ");
	input = input_string();

	printf("yar: %s\n", input);

	free(input);
	return 0; 
}
