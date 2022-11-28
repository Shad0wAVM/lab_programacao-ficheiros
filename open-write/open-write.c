/*
 * open-write.c
 *
 * Simple example of opening and writing to a file.
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
    * the attributes are:
    * - O_CREAT: create the file if it does not exist
    * - O_TRUNC: erase the contents of the file
    * - O_WRONLY: open the file for writting
    *
    * the permissions are applied if the file is created:
    * - S_IRUSR: reading, user
    * - S_IWUSR: writting, user
    */
   FILE *file = fopen("test.txt", "w");
   if (!file){
      fprintf(stderr, "open error: %s\n", strerror(errno));
      return -1;
   }

   char buffer[] = "Hello World!\n";

   /* write a string to the file */
   size_t bytes_written = fwrite(&buffer, sizeof(char), strlen(buffer), file);
   if (bytes_written < 0){
      fprintf(stderr, "write error: %s\n", strerror(errno));
      return -1;
   }

   /* close the file */
   fclose(file);

   return 0;
}
