#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int main() {
    
    bool KEEP_RUNNING = true; // Variable to keep Do-While running while the player wants to keep playing.
    srand(time(NULL)); // Makes sure the random numbers have a equal distribution.
    int randomNumber = rand() % 100 +1 ; // Generates a number between 1-100.
    int totalGuesses = 0; // Initialize the number of guesses for a given game.

    do {
        int currentGuess; // Initialize an int to store the number the user guesses.
        //Requests the guess from the user and stores it in the currentGuess variable.
        printf("Enter a guess between (1-100): \n");
        scanf("%d", &currentGuess);
        // Incrementing the number of guesses for the current game.
        totalGuesses++;
        if (currentGuess > 100 || currentGuess < 0) {
            printf("Your guess was out of the range! Please pick a number between 1-100 \n");
            continue;
        }
        else if (currentGuess < randomNumber) {
            /* Check if the guessed number is less than the generated number. 
            If this is true user is informed and rest of loop is skipped for this iteration. */
            printf("Your guess was too low, try again! \n");
            continue;
        } // The usage of continue is not needed but does in my opinion help with following the execution of the code in terms of readability.
            /* Similar to the check above we now instead check if the number is greater than
            the number we have generated, if this is true we simply inform the user and skip to next iteration.*/
        else if (currentGuess > randomNumber) {
            printf("Your guess was too high, try again! \n");
            continue;
        }
        // If we reach this section it means that the guess equals the random number we have generated. 
        // The user is informed that they gusses the correct number, and prompted to either exit the program by entering 2 or keep playing by entering 1.
        else {
            printf("You have guessed %d times, and your guess is correct \n", totalGuesses);
            printf("Type 1 to play again, type 2 to exit \n");
            int playAgain; // Stores the user choice
            scanf("%d", &playAgain);
            // Checking if the user wishes to exit, if this is true the KEEP_RUNNING variable is changed to false which will cause the loop to exit.
            if (playAgain == 2) {
                KEEP_RUNNING = false;
            } else if (playAgain == 1) {
                // In the case that the user whishes to keep playing the totalGuesses are reset to 0 and a new number is generated.
                randomNumber = rand() % 100 +1 ;
                totalGuesses = 0;
            }
        }

    } while (KEEP_RUNNING && totalGuesses < INT8_MAX); /* Checks that KEEP_RUNNING is still set to true AND that the total_guesses is within the number constraint
                                                        of an integer */
    
}