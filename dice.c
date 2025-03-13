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
 typedef struct {int sides;
                int count;} RollType;

/*** utilities ***/
void die() {
    printf("ERROR: Invalid command line argument passed into program.\n");
    exit(-1);
}

 /*** mechanics ***/
 int roll_die(int sides) {
    return rand() % sides + 1;
 }

/*** init ***/
int main(int argc, char** argv) {
    srand(time(NULL));
    regex_t rollRegex;
    regcomp(&rollRegex, "^[c,d][0,1,2,3,4,5,6,7,8,9]\\{1,3\\}$", REG_NOSUB);

    /*Parse command line arguments*/
    const int USER_ROLLS_MAX = 20;
    RollType userRolls[USER_ROLLS_MAX];
    int userRollsTail = -1;

    for (int i = 1; i < argc; i++) {
        if (regexec(&rollRegex, *(argv + i), 0, NULL, 0) != 0) {
            die();
        }
        if (i == 1 && **(argv + i) != 'd') {
            die();
        }
        if (**(argv + i) == 'd') {
            userRollsTail++;
            if (userRollsTail == USER_ROLLS_MAX) {
                printf("Maximum number of dice types exceeded.\n");
                userRollsTail--;
                break;
            }
            userRolls[userRollsTail].sides = atoi(*(argv + i) + 1);
            userRolls[userRollsTail].count = 1; //default count
        }
        if (**(argv + i) == 'c' && **(argv + i - 1) != 'd') {
            die();
        }
        if (**(argv + i) == 'c' && **(argv + i - 1) == 'd') {
            userRolls[userRollsTail].count = atoi(*(argv + i) + 1);
        }
    }

    int result;

    /*roll dice and display results*/
    for (int i = 0; i <= userRollsTail; i++) {
        printf("d%d: ", userRolls[i].sides);
        for (int j = 0; j < userRolls[i].count; j++) {
            result = roll_die(userRolls[i].sides);
            printf("[%d]", result);
        }
        printf("\n");
    }


    return 0;
}