#include "read.h"

int read_string(char *string) {
  if (fgets(string, STR_LEN, stdin)) {
    return 1;
  } else {
    printf("can't read string!\n");
    return 0;
  }
}
int read_number(int *number) {
  char buff[STR_LEN];
  if (fgets(buff, sizeof(buff), stdin)) {
    if (sscanf(buff, "%d", number) == 0) {
      printf("can't read number!\n");
      return 0;
    }
  }
  return 1;
}