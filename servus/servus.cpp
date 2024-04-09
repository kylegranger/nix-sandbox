#include <stdio.h>


int main(int argc, char **argv)
{
  printf("Servus!\n");
  printf("main(): argc %d\n", argc);
  printf("  args:\n");
  for (int i = 0; i < argc; i++) {
    printf("    %d, %s\n", i, argv[i]);
  }
  return 0;
}