#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>


int main(){
  struct stat file;
  int k;
  k = stat("main.c", &file);
  if (k < 0){
    printf("Error %d: %s\n", errno, strerror(errno));
    return 1;
  }

  float fileSize = file.st_size;
  float fileSize_GB = fileSize / 1000000000;
  float fileSize_MB = fileSize / 1000000;
  float fileSize_KB = fileSize / 1000;
  printf("File Size in GigaBytes: %f GB \n", fileSize_GB);
  printf("File Size in MegaBytes: %f MB \n", fileSize_MB);
  printf("File Size in Kilobytes: %f KB \n", fileSize_KB);
  printf("File Size in Bytes: %f B \n", fileSize);

  printf("\nPermissions (normal): %o\n", file.st_mode);
  char p[7];
  sprintf(p, "%o", file.st_mode);
  int i = 3;
  printf("Permissions (ls-l format): ");
  for (; i < 7; i++) {
    switch (p[i] - 48){
      case 0:
        printf("---");
        break;
      case 1:
        printf("--x");
        break;
      case 2:
        printf("-w-");
        break;
      case 3:
        printf("-wx");
        break;
      case 4:
        printf("r--");
        break;
      case 5:
        printf("r-x");
        break;
      case 6:
        printf("rw-");
        break;
      case 7:
        printf("rwx");
        break;
    }
  }
  
  printf("\n\nTime of Last Access: %s\n", ctime(&file.st_atime));
  return 0;
}
