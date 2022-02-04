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
    file=fopen("record.bin","wb");

    fwrite(inrecord, sizeof(PERSON) , 1, file);
    fclose(file);
};  // Creates a file and  


// writes the first record 
     
void printfile(void) {  // Prints out all persons in the file
    FILE *file;
    PERSON person;
    file = fopen("record.bin", "rb");
    while (fread(&person, sizeof(PERSON), 1, file) > 0) {
        printf("%s %s %s \n", person.firstname, person.famname, person.pers_number);
    }   
}
void search_by_firstname(char *name) {
    FILE *file;
    PERSON person;
    file = fopen("record.bin", "rb");

    while (fread(&person, sizeof(PERSON), 1, file) > 0) {
        if (strcmp(name, person.firstname) == 0 || strcmp(name, person.famname) == 0) {
            printf("%s %s %s \n", person.firstname, person.famname, person.pers_number);
        } 
    }   

   fclose(file); 
}; // Prints out the person if    
// in list  
void append_file(PERSON *inrecord){
    FILE *fptr;
    fptr=fopen("record.bin","ab");
    fwrite(inrecord, sizeof(PERSON), 1, fptr );
    fclose(fptr);
};    // appends a new person to the file 
 
int main(void){ 
    int choice;
    char query[20];
    //Dummy record
    PERSON ppost;
    strcpy(ppost.firstname, "name");
    strcpy(ppost.famname, "lastname");
    strcpy(ppost.pers_number, "0000221133");


    //User menu
    printf("1. Create a new and delete the old file.\n");
    printf("2. Add a new person to the file. \n");
    printf("3. Search for a person in the file. \n");
    printf("4. Print out all in the file. \n");
    printf("5. Exit the program.\n\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        write_new_file(&ppost);
        break;
    case 2:
        append_file(&ppost);
        break;
    case 3:
        printf("Enter name to search for.\n");
        scanf("%s", &query);
        search_by_firstname(&query);
        break;
    case 4:
        printfile();
        break;
    case 5:
        return 0;
        break;
    default:
        break;
    }
    return 0;     
} 