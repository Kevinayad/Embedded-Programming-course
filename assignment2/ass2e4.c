#include <stdio.h>
#include <stdlib.h>


int main()
{
   FILE *fp;
   int c;
  
   fp = fopen("test2,bin","rb");



   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);

return 0;
}