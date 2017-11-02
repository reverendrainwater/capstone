//    PROGRAM-ID. yessviz
//        AUTHOR. Rev. Taylor R. Rainwater
// LAST-REVISION. 2017-11-02

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

// Headers
#include "yessviz.h"

// Defined Values
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

/**
 * input file
 * args: 
 * char pointer
 * returns: 
 * char pointer
 * description:
 * When called with a file name passed,
 * it opens a file in read mode. Once open
 * the function reads the file into a char
 * array then returns the array to the caller. 
 */
char *input_file(char *filename)
{	FILE *fp;
	char *str;

	// open file
	fp = fopen(filename, "r");
	// determine file size
	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	rewind(fp);
	// allocate size
	str = malloc(fsize);
	// read file
	fread(str, fsize, 1, fp);
	// terminate string properly
	str[fsize] = '\0';
	// close file, return string
	fclose(fp);
	return str;	
}

/**
 * count_difference
 * args:
 * two char pointers
 * returns: 
 * int
 * description:
 * scans through the two files and returns
 * the total amount of different characters 
 * between the two files.
 */
int count_difference(char *student, char *instructor)
{       int count, i = 0;
	// scan through files and determine which characters are different
	// used for testing now
	for (i = 0; i < strlen(student); i++){
		if (student[i] != instructor[i]){
			count++;
		}
	}
	return count; 
}

/**
 * main
 * args: 
 * none
 * return:
 * int - 0, no error; 1, error 
 * description:
 * Where the magic happens. This makes
 * the necessary calls to start the 
 * program. 
 */
int main(int argc, char *argv[])
{	char *s_file_body;
	char *i_file_body;
	int difference = 0;
	
	// get file bodies
	s_file_body = input_file(argv[1]);
	i_file_body = input_file(argv[2]);

	// create ncurses interface
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	// get difference count
	difference = count_difference(s_file_body, i_file_body);
	attron(A_BOLD);
	printw("DIFFERENCE COUNT: %i\n", difference);
	attroff(A_BOLD);

	refresh();
	getch(); 
	endwin(); // close window
	
	free(s_file_body);
	free(i_file_body);
	return 0; 
}
