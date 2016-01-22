#include <iostream>
#include <algorithm>

using namespace std;

int solution( int N )
{
  uint32_t i=1;
  uint32_t N2(N);
  uint32_t minPerim=2*(1+N);
  while( i*i < N2 ) {
    if( N2%i == 0 ) {
      int j=N2/i;
      minPerim = min(minPerim, 2*(i+j) );
    }
    i++;
  }
  if( i*i == N2 ) {
    minPerim = min(minPerim, 2*(i+i) );
  }
  return minPerim;
}

int main(int argc, char **argv) {
  std::cout << solution(30) << std::endl;
  std::cout << solution(1000000000) << std::endl;
  return 0;
}
