#ifndef COMMAND_H
#define COMMAND_H

struct Command {
  char operation;
  char *initial_string;
  char *substitute_string;
  char scope;
};

struct Command parse(char *command);

#endif
