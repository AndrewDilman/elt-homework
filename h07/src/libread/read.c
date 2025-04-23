#include "read.h"

// int read_string(char *string) {
//   if (scanf("%s", string)) {
//     return 1;
//   } else {
//     printf("can't read string!\n");
//     return 0;
//   }
// }
int read_string(char *str) {
  char buff[STR_LEN];
  if (fgets(buff, sizeof(buff), stdin)) {
    if (sscanf(buff, "%s", str) == 0) {
      printf("can't read string!\n");
      return 1;
    }
  }
  return 0;
}
int read_number(float *number) {
  char buff[STR_LEN];
  if (fgets(buff, sizeof(buff), stdin)) {
    if (sscanf(buff, "%f", number) == 0) {
      printf("can't read number!\n");
      return 1;
    }
  }
  return 0;
}