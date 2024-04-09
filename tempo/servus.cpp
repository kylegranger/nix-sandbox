#include <stdio.h>
#include <omp.h>


int main(int argc, char **argv)
{
  printf("Servus!\n");
  printf("main(): argc %d\n", argc);
  printf("  args: \n");
  for (int i = 0; i < argc; i++) {
    printf("    %d, %s\n", i, argv[i]);
  }

  auto nthreads = omp_get_num_threads();
  auto mthreads = omp_get_max_threads();
  auto nprocs = omp_get_num_procs();
  printf("omp_get_num_threads: %d\n", nthreads);
  printf("omp_get_max_threads: %d\n", mthreads);
  printf("omp_get_num_procs: %d\n", nprocs);

  return 0;
}