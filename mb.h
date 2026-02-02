#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool checkKeyword(char *token, char **keywords) {
  for (int i = 0; i < 3; i++) {
    if (strcmp(keywords[i], token) == 0) {
      return true;
    }
  }
  return false;
}

bool checkForEqual(char *token) {
  for (int i = 0; i < strlen(token); i++) {
    if (token[i] == '=') {
      return true;
    }
  }
}

int calValues(int *x, char op, int size) {
  int res = 0;

  for (int i = 0; i < size; i++) {
  }
  switch (op) {
  case ('+'):
    res = 0;
    for (int i = 0; i < size; i++) {

      res += x[i];
    }
    break;
  case ('-'):
    res = 0;
    for (int i = 0; i < size; i++) {
      res += x[i] - res;
      break;
    }
  case ('*'):
    res = 1;
    for (int i = 0; i < size; i++) {
      res *= x[i];
      break;
    }

  case ('/'):
    res = 1;
    for (int i = 0; i < size; i++) {
      res /= x[i];
      break;
    }
  }
  return res;
}
