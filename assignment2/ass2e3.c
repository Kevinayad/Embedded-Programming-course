#include <stdlib.h> 
#include <stdio.h> 
 #include <string.h>
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend)  
PERSON input_record(void);             // Reads a person’s record. 


void write_new_file(PERSON *inrecord){
    FILE *file;
    file=fopen("record.bin","wb"); // Opens the file, creates one if it doesnt exist.

    fwrite(inrecord, sizeof(PERSON) , 1, file); // Writes the person record to the file.
    fclose(file);
};  // Creates a file and  


// writes the first record 
     
void printfile(void) {  // Prints out all persons in the file
    FILE *file;
    PERSON person;
    file = fopen("record.bin", "rb"); // Opens file
    while (fread(&person, sizeof(PERSON), 1, file) > 0) { // Loops over all persons in the binary file
        printf("%s %s %s \n", person.firstname, person.famname, person.pers_number); // Prints current instance of person struct
    }   
    fclose(file);
}
void search_by_firstname(char *name) {
    FILE *file;
    PERSON person;
    file = fopen("record.bin", "rb"); // Opens file

    while (fread(&person, sizeof(PERSON), 1, file) > 0) { // Loops over all the persons in the file.
        if (strcmp(name, person.firstname) == 0 || strcmp(name, person.famname) == 0) { // If the query equals either name or last name we print the person
            printf("%s %s %s \n", person.firstname, person.famname, person.pers_number); // Prints if true
        } 
    }   

   fclose(file); 
}; // Prints out the person if    
// in list  
void append_file(PERSON *inrecord){
    FILE *fptr;
    fptr=fopen("record.bin","ab"); // Opens file
    fwrite(inrecord, sizeof(PERSON), 1, fptr ); // Writes to the file
    fclose(fptr); // Closes file
};    // appends a new person to the file 
 
int main(void){ 
    int choice;
    char query[20];
    //Dummy record
    PERSON ppost;
    strcpy(ppost.firstname, "name"); // person dummy data
    strcpy(ppost.famname, "lastname");
    strcpy(ppost.pers_number, "0000221133");


    //User menu
    while (1) { // Keeps looping over the menu until users presses 5 and exists.

    printf("1. Create a new and delete the old file.\n"); // Prints all menu options
    printf("2. Add a new person to the file. \n");
    printf("3. Search for a person in the file. \n");
    printf("4. Print out all in the file. \n");
    printf("5. Exit the program.\n\n");
    scanf("%d",&choice); // Listens for user input

    switch (choice) // Switch statment to check the user input
    {
    case 1:
        write_new_file(&ppost); // creates new file if doesnt exist and overwrites if it does.
        break;
    case 2:
        append_file(&ppost); // Appends person to file
        break;
    case 3:
        printf("Enter name to search for.\n"); 
        scanf("%s", &query); // Gets user query to search for first name or last name
        search_by_firstname(&query); // searchs for the query
        break;
    case 4:
        printfile(); // Prints entire file
        break;
    case 5:
        return 0;
        break;
    default:
       return 0;     
    }
} 
}