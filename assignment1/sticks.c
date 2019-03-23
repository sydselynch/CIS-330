#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

int getUserChoice() {

      int num_sticks;
      int valid = 0;
      char non_int;

      while (valid == 0) {
        printf("Player 1: How many sticks do you take (1-3)? ");
        if (scanf("%d", &num_sticks) == 0) {
          scanf("%s", &non_int);  // Collect non-integer input and remove from buffer to avoid infinite recursion
          printf("The number of sticks must be an integer (1, 2, or 3).\n");
          printf("\n");
        }
        
        else if (num_sticks < 1 || num_sticks > 3) {
          printf("The number of sticks must be 1, 2, or 3.\n");
          printf("\n");
        }
        else {
          valid = 1;
        }
      }
      return num_sticks;

}

int getComputerChoice(int current_sticks) {

    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;

    if (rand_choice > current_sticks) return current_sticks;

    /* Optionally replace with additional logic for the computer's strategy */

    return rand_choice;
}


int main(int argc, char** argv) 
{
    int user, computer, number_sticks;


    srand (time(NULL)); /* for reproducible results, you can call srand(1); */

    printf("Welcome to the game of sticks!\n");
    printf("How many sticks are there on the table initially (10-100)? ");
    scanf("%d", &number_sticks);

    if (number_sticks > 100 || number_sticks < 10) {
      printf("The number of sticks on the table must be an integer between 10-100 (inclusive).");
      return 0;
    }

    printf("There are %d sticks on the board.\n", number_sticks);
    while (number_sticks != 0) {
      user = getUserChoice();
      if (user > number_sticks) {
        while (user > number_sticks) {
          printf("That number is greater than the number of sticks, choose again.\n");
          user = getUserChoice();
        }
      }
      
      number_sticks = number_sticks - user;
      if (number_sticks < 1) {
        printf("You lose!\n");
        return 0;
      }
      printf("There are %d sticks on the board.\n", number_sticks);
      computer = getComputerChoice(number_sticks);
      printf("Computer selects %d\n", computer);
      printf("\n");

      number_sticks = number_sticks - computer;
      if (number_sticks < 1) {
        printf("You win!\n");
        return 0;
      }
      printf("There are %d sticks on the board.\n", number_sticks);

    }

    return 0;
}
