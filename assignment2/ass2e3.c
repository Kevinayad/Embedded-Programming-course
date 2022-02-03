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
FILE *fptr;
fptr=fopen("record1.bin","wb");
// char firstname->inrecord.firstname;
// char famname->inrecord.famname;
// char pers_number->inrecord.famname;
fwrite(inrecord->firstname, 1 , sizeof(inrecord->firstname) , fptr );
fwrite(inrecord->famname, 1 , sizeof(inrecord->famname) , fptr );
fwrite(inrecord->pers_number, 1 , sizeof(inrecord->pers_number) , fptr );
fclose(fptr);
};  // Creates a file and  


// writes the first record 
void printfile(void);     // Prints out all persons in the file 
void search_by_firstname(){
    int c;
FILE *file;
file = fopen("record.bin", "rb");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
}
}; // Prints out the person if    
// in list  
void append_file(PERSON *inrecord){
FILE *fptr;
fptr=fopen("record1.bin","ab");
fwrite(inrecord->firstname, 1 , sizeof(inrecord->firstname) , fptr );
fwrite(inrecord->famname, 1 , sizeof(inrecord->famname) , fptr );
fwrite(inrecord->pers_number, 1 , sizeof(inrecord->pers_number) , fptr );
fclose(fptr);
};    // appends a new person to the file 
 
int main(void){ 
    PERSON ppost;
    int choice;
     strcpy(ppost.firstname,"kevin");
     strcpy(ppost.famname,"ayad");
     strcpy(ppost.pers_number,"0003116233");
    printf("1. Create a new and delete the old file.\n");
    printf("2. Add a new person to the file. \n");
    printf("3. Search for a person in the file. \n");
    printf("4. Print out all in the file. \n");
    printf("5. Exit the program.\n\n");
    scanf("%d",&choice);
    if(choice==1){
        write_new_file(&ppost);
        
    }else if(choice==2){
        append_file(&ppost);
    }else if(choice==3){
        search_by_firstname;
    }
    return(0);     
} 