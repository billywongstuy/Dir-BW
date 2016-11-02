#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  DIR * stream = opendir(".");
  struct dirent *dp;
  int size = 0;
  int error;
  struct stat *staty = (struct stat *)malloc(sizeof(struct stat));

  while (dp = readdir(stream)) {
    printf("Name: %s\n",dp->d_name);
    if (dp->d_type == 4) {
      printf("This is a directory!\n");
    }
    error = stat(dp->d_name,staty);
    size += staty->st_size;

    printf("\n");
  }

  printf("Size: %d B\n",size);
  closedir(stream);

  return 0;
}

/*

list all the files in the directory
specify which files are directories (if any)
show the total size of all the regular files the directory
note that you do not have to recursively go through any subdirectories to find their size for this part (unless you want to, but that is not a simple task)
Have the program scan the current directory
Possible enhancements:
Recursively list the files in any subdirectories, update the total to include the total size of subdirectories
Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)

 */
