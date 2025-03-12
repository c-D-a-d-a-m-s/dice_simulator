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

 /*** constants ***/
 const int D6 = 6;

 /*** mechanics ***/
 int roll_die(int sides) {
    return rand() % sides + 1;
 }

/*** init ***/
int main() {
    srand(time(NULL));
    int result;
    result = roll_die(D6);
    printf("d6: %d\n\n", result);

    return 0;
}