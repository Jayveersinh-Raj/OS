//This is a program to print the contents of the root directory

#include <dirent.h> 
#include <stdio.h> 

int main(void) {
  DIR *dr;
  struct dirent *dir;
  dr = opendir("/");
  if (dr) {
    while ((dir = readdir(dr)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(dr);
  }
  return(0);
}
