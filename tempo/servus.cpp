#include <stdio.h>
#include <omp.h>
#include <string>



uint8_t* utilReadTextFile(std::string filename, size_t* filelen) {
    printf("utilReadTextFile %s\n", filename.c_str());
    FILE* f = fopen(filename.c_str(), "rb");
    if (!f) {
        printf("could not open file %s\n", filename.c_str());
        return nullptr;
    }
    fseek(f, 0L, SEEK_END);
    *filelen = ftell(f);
    fseek(f, 0L, SEEK_SET);

    printf("   file len %zd\n", *filelen);
    // allocate one more byte for text
    uint8_t* data = new uint8_t[*filelen + 1];
    size_t result = fread(data, 1, *filelen, f);
    fclose(f);
    if (result != *filelen) {
        delete[] data;
        return nullptr;
    }
    data[*filelen] = 0;
    //printf("read data: %s\n", data);
    return data;
}


int main(int argc, char **argv)
{
  printf("Servus!\n");
  printf("main(): argc %d\n", argc);
  printf("  args:\n");
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