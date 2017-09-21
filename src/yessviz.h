//     HEADER-ID. yessviz.
//        AUTHOR. Rev Taylor R Rainwater (trr).
// LAST-REVISION. 2017-09-21

// Define Variables
#define DUMPLIMIT 256

/**
 * Cycle
 * description:
 * This is used to store a single 
 * cycle (i.e. the text from the dump).
 * 
 */
struct Cycle {
	char *Body; // actual text
}

/**
 * Dump
 * description:
 * This is used to store the cycles.  
 *
 */
struct Dump {
	struct Cycle Cycles[DUMPLIMIT]; // array of cycles
	int Type; // instructor or student
} Dump;
