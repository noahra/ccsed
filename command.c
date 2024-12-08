#include "command.h"
#include <stdlib.h>
#include <string.h>

struct Command parse(char *command) {
  struct Command cmd;
  cmd.operation = command[0];
  char *first_slash = strchr(command, '/');
  if (first_slash) {
    char *second_slash = strchr(first_slash + 1, '/');
    if (second_slash) {
      char *third_slash = strchr(second_slash + 1, '/');
      int initial_len = second_slash - (first_slash + 1);
      int substitute_len = third_slash - (second_slash + 1);

      cmd.initial_string = malloc(initial_len + 1);
      cmd.substitute_string = malloc(substitute_len + 1);

      strncpy(cmd.initial_string, first_slash + 1, initial_len);
      cmd.initial_string[initial_len] = '\0';
      strncpy(cmd.substitute_string, second_slash + 1, substitute_len);
      cmd.substitute_string[substitute_len] = '\0';

      cmd.scope = third_slash[1];
    }
  }
  return cmd;
}
