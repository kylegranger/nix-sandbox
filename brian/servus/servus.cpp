#include <stdio.h>
#include <memory.h>
#include <omp.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>

std::string exec(const char* cmd) {
    printf("exec cmd: %s\n", cmd);
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

void writeContents(std::string contents, const char *filename) {
    printf("writeContents to file %s\n", filename);
    std::string output = "I did read this text in, which I now wrote out as proof.\n" + contents;
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("could not open file %s\n", filename);
        return;
    }
    auto filelen = output.length();
    size_t result = fwrite(output.c_str(), 1, filelen, f);
    fclose(f);

}


char* utilReadTextFile(std::string filename) {
    printf("utilReadTextFile %s\n", filename.c_str());
    FILE* f = fopen(filename.c_str(), "rb");
    if (!f) {
        printf("could not open file %s\n", filename.c_str());
        return nullptr;
    }
    fseek(f, 0L, SEEK_END);
    auto filelen = ftell(f);
    fseek(f, 0L, SEEK_SET);

    printf("   file len %zd\n", filelen);
    // allocate one more byte for text
    char* data = new char[filelen + 1];
    size_t result = fread(data, 1, filelen, f);
    fclose(f);
    if (result != filelen) {
        delete[] data;
        return nullptr;
    }
    data[filelen] = 0;
    //printf("read data: %s\n", data);
    return data;
}

void doSomeSystemCalls() {
    auto result = exec((char *)"ls -l ./workspace");
    printf(" result: %s", result.c_str());
    result = exec((char *)"ls -l /workspace");
    printf(" result: %s", result.c_str());
    // result = exec((char *)"ls -l");
    // printf(" result: %s", result.c_str());
    // result = exec((char *)"ls -l /nix/store");
    // printf(" result: %s", result.c_str());
}


int main(int argc, char **argv)
{
  printf("Servus!\n");
  printf("main(): argc %d\n", argc);
  printf("  args: \n");
  for (int i = 0; i < argc; i++) {
    printf("    %d, %s\n", i, argv[i]);
  }

  doSomeSystemCalls();
  std::string contents = utilReadTextFile(argv[1]);
  writeContents(contents, argv[2]);
  auto nthreads = omp_get_num_threads();
  auto mthreads = omp_get_max_threads();
  auto nprocs = omp_get_num_procs();
  printf("omp_get_num_threads: %d\n", nthreads);
  printf("omp_get_max_threads: %d\n", mthreads);
  printf("omp_get_num_procs: %d\n", nprocs);

  return 0;
}