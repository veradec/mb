#include "mb.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc(char *argument) {
  char op;
  char *buf = strtok(argument, " ");
  int size = strlen(argument);
  int x[size];
  int count = 0;
  while (buf != NULL) {
    if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/') {
      op = buf[0];
    } else {
      x[count] = atoi(buf);
      count++;
    }

    buf = strtok(NULL, " ");
  }
  printf("%d\n", calValues(x, op, count));
}

void doTask(char *token, char *argument) {

  /* printf("\ngot token -> %s | argument -> %s\n", token, argument); */
  if (strcmp(token, "chepparafool") == 0) {
    // TODO: Parse Escape Sequences
    printf("%s", argument);
  } else if ((strcmp(token, "lawsuit")) == 0) {
    int status = atoi(argument);
    exit(status);
  } else if ((strcmp(token, "choodu")) == 0) {
    calc(argument);
  }
}

void parseLine(char *line, char **keywords) {
  while (line != NULL) {
    if (checkKeyword(line, keywords)) {
      char *rest = strtok(NULL, "");
      doTask(line, rest);
    } else {
      if (checkForEqual(line)) {
        char *rest = strtok(NULL, "=");
        setVariable(line, rest);
      }
    }
    line = strtok(NULL, " ");
  }
}

int main() {
  FILE *f = fopen("sonofindia.mb", "r");
  // ADD WRITING TO Binaries Later.
  /* FILE *o = fopen("sonofindia.hit", "wb"); */
  char buf[256];
  char *keywords[] = {"chepparafool", "lawsuit", "choodu"};

  while (fgets(buf, 256, f) != NULL) {
    char *lines = strtok(buf, " ");
    parseLine(lines, keywords);
  }

  return 0;
}
