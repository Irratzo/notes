
#include <omp.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int * fnums;
int * fnums_done;


int fib1(int n){
  //naive code.
  //bad cause intermed results are computed repeatedly.
  int i, j;
  if (n >= 2){
    i = fib1(n-1);
    j=fib1(n-2);
    fnums[n] = i+j;
  }
  return fnums[n];
}

int fib2(int n){
  //naive improved:
  //remember already computed intermed results
  
}


int parseArgs(char** argv){
  std::string arg = argv[1];
  int x = -1;
  try {
    std::size_t pos;
    x = std::stoi(arg, &pos);
    if (pos < arg.size()) {
      std::cerr << "Trailing characters after number: " << arg << '\n';
    }
  } catch (std::invalid_argument const &ex) {
    std::cerr << "Invalid number: " << arg << '\n';
  } catch (std::out_of_range const &ex) {
    std::cerr << "Number out of range: " << arg << '\n';
  }
  return x;
}

int main(int argc, char** argv){
  
  int N = parseArgs(argv);

  fnums = new int[N+1];
  fnums[0] = 1;
  fnums[1] = 1
  int fibN = fib1(N);
  std::cout << "fib(" << N << ")=" << fibN << std::endl; 

  return EXIT_SUCCESS;
}
