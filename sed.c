
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
