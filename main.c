#include <stdio.h>

int add(int a, int b) { return a + b; }
void greet(const char *name) { printf("Hello, %s!\n", name); }
int main() { printf("%d\n", add(1, 2)); return 0; }