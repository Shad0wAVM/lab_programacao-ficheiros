/*
 * open-read.c
 *
 * Simple example of opening and reading to a file.
 *
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[])
{
   /*
    *
    * the attributes are:
    * - O_RDONLY: open the file for reading
    *
    */
   FILE *file = fopen("test.txt", "r");
   if (!file){
      fprintf(stderr, "open error: %s\n", strerror(errno));
      return -1;
   }

   char buffer[128];
   memset(buffer,0,sizeof(buffer));
   size_t test = fread(&buffer, sizeof(char), 127, file);
   while (test!= 0){

      printf("%s",buffer);

      memset(buffer,0,sizeof(buffer));

      /* read the contents of the file */
      test = fread(&buffer, sizeof(char), 127, file);
      if (test < 0){
         fprintf(stderr, "read error: %s\n", strerror(errno));
         return -1;
      }

      
   }
   /* close the file */
   fclose(file);

   return 0;
}
