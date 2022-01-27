// Kevin, Anis, Vlad, group: 26 __ (2022) 
// Work package 1 
// Exercise 5
// Submission code: ATb-Fc1 (provided by your TA-s) 

#include <stdio.h> 
#include <stdlib.h> 
 #include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab ) {
    srand(time(NULL)); // Makes sure the random numbers have a equal distribution.
    for(int i; i < MAX; i++) { // Loops over the max amount of numbers.
        tab[i] = rand() % MAXNUMBER+1; // Random numbers within the given range are generated and saved to the current array index. 
    }
}
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ) {
    for (int i = 0; i <= MAXNUMBER; i++) { //Loops over all distinct numbers between 0 and the range of MAXNUMBER.
       freq[i] = 0; // It initializes these array values to 0 to make it possible to increment the value everytime the number is encountered
    }
    for (int i = 0; i < MAX; i++) { // Loops over the number of random numbers.
        int number = tab[i]; // Temporarily stores the current number in variable
        freq[number]++; // The number maps to the matching index, and the number which starts from 0 gets incremented at the given index.
    }
}
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq ) {
    for (int i = 0; i <= MAXNUMBER; i++) { // Loops over all possible distinct numbers that could be generated.
    int frequency = freq[i]; // Temporarily stores the frequency for a given number.
    if (frequency == 0) { // The frequency is compared to 0, if this is true we don't want to print this number frequency and therefore continue.
        continue; // Continues to next iteration of for-loop.
    }
    printf("%d ", i); // Prints current number being looked at.
    for (int j = 0; j <= frequency; j++) { // Looping over the frequency value for a number to play j amounts of x.
        printf("x");
    }
    printf("\n"); // Breaks to new line to properly format the output in the terminal.
}
}
 
// ------ Function definitions   ---------- 
 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly 

int main (void){ 
    int table[MAX], n ; 
    int frequency[MAXNUMBER]; 
    create_random(table); // Populates the table array with MAX amount of random numbers within the range MAXNUMBER.
    count_frequency(table, frequency); // Counts the frequency of each distinct number and populates the data in the frequency array.
    draw_histogram(frequency); // Output the frequency data to the terminal.
} 