/*************************************************************
 * File: dice.c                                              *
 * Description: Simulate rolling dice in CLI environment.    *
 * Author: Christopher Adams                                 *
 * Date Created: 2025-03-10                                  *
 * Last Modified: 2025-03-10                                 *
 * Version: 1.0                                              *
 *                                                           *
 *************************************************************/

 /*** includes ***/
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
 #include <regex.h>

 /*** user-defined data type ***/
 typedef struct {int sides;} RollType;

 /*** mechanics ***/
 int roll_die(int sides) {
    return rand() % sides + 1;
 }

/*** init ***/
int main(int argc, char** argv) {
    srand(time(NULL));
    regex_t rollRegex;
    regcomp(&rollRegex, "^[0,1,2,3,4,5,6,7,8,9]*$", REG_NOSUB);

    for (int i = 1; i < argc; i++) {
        if (regexec(&rollRegex, *(argv + i), 0, NULL, 0) != 0) {
            printf("ERROR: Invalid command line argument passed into program.\n");
            exit(-1);
        }
    }

    for (int i = 1; i < argc; i++) {
        int sides = atoi(*(argv + i));
        int result;

        result = roll_die(sides);
        printf("d%d: %d\n\n", sides, result);
    }


    return 0;
}