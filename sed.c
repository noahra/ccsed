
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Command {
  char operation;
  char *initial_string;
  char *substitute_string;
  char scope;
};

struct Command parse(char *command) {
  struct Command cmd;
  cmd.operation = command[0];
  char *first_slash = strchr(command, '/');
  if (first_slash) {
    char *second_slash = strchr(first_slash + 1, '/');
    if (second_slash) {
      char *third_slash = strchr(second_slash + 1, '/');

      // Calculate lengths and allocate memory
      int initial_len = second_slash - (first_slash + 1);
      int substitute_len = third_slash - (second_slash + 1);

      cmd.initial_string = malloc(initial_len + 1);
      cmd.substitute_string = malloc(substitute_len + 1);

      // Copy the strings
      strncpy(cmd.initial_string, first_slash + 1, initial_len);
      cmd.initial_string[initial_len] = '\0';

      strncpy(cmd.substitute_string, second_slash + 1, substitute_len);
      cmd.substitute_string[substitute_len] = '\0';

      // Get scope if it exists
      cmd.scope = third_slash[1];
    }
  }

  return cmd;
}
int main(int argc, char *argv[]) {

  struct Command cmd;
  char *testvar = argv[2];

  FILE *txt_file;

  txt_file = fopen(testvar, "r");

  char *command = argv[1];
  cmd = parse(argv[1]);

  printf("Operation: %c\n", cmd.operation);
  printf("Initial string: %s\n", cmd.initial_string);
  printf("Substitute string: %s\n", cmd.substitute_string);
  printf("Scope: %c\n", cmd.scope);

  return 0;
}
