#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

bool find(vector<int>::iterator Pb, vector<int>::iterator Pe, const int min, const int max)
{
  if( distance(Pb, Pe)==0 ) {
    return false;
  }
  if( distance(Pb, Pe)==1 ) {
    return ( *Pb >= min && *Pb <= max );
  }
  int middle=*(Pb + distance(Pb, Pe)/2);
  if( middle > max ) {
    return find( Pb, (Pb + distance(Pb, Pe)/2), min, max );
  }
  if( middle < min ) {
    return find( (Pb + 1 + distance(Pb, Pe)/2), Pe, min, max);
  }
  return true;
}

int solution( vector<int> &A )
{
  vector<int> peaks;
  const uint32_t size=A.size();
  for( uint32_t i=1; i<size-1; i++ ) {
    if( A[i-1] < A[i] && A[i] > A[i+1] )
      peaks.push_back(i);
  }
  const uint32_t pSize = peaks.size();
  uint32_t i = 1; // number of blocks
  uint32_t maxBlocks = 0;
  while( i<=pSize ) {
    if( size%i == 0 ) {
      uint32_t bsize=size/i; // blockSize
      uint32_t j=0;
      for( ; j<i; j++ ) {
	if( !find(peaks.begin(),peaks.end(), j*bsize, (j+1)*bsize-1))
	  break;
      }
      if( i == j ) {
	maxBlocks=i;
      }
    }
    i++;
  }
  return maxBlocks;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(1);
  A.push_back(2);
  A.push_back(3);
  A.push_back(4);
  A.push_back(3);
  A.push_back(4);
  A.push_back(1);
  A.push_back(2);
  A.push_back(3);
  A.push_back(4);
  A.push_back(6);
  A.push_back(2);
  std::cout << solution(A) << std::endl;
  vector<int> C;
  C.push_back(5);
  std::cout << solution(C) << std::endl;
  C.push_back(10);
  std::cout << solution(C) << std::endl;
  C.push_back(10);
  std::cout << solution(C) << std::endl;
  vector<int> B;
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  std::cout << solution(B) << std::endl;
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  std::cout << solution(B) << std::endl;
  return 0;
}
