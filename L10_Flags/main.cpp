#include <iostream>
#include <vector>

using namespace std;

int solution( vector<int> &A ) {
  const uint32_t size=A.size();
  vector<int> peaks;
  for( uint32_t i=1; i<size-1; i++ ) {
    if( A[i-1] < A[i] && A[i] > A[i+1] )
      peaks.push_back(i);
  }
  uint32_t i=1; // flags number == distance between peaks
  uint32_t maxFlag=0;
  const uint32_t pSize=peaks.size();
  while( i <= pSize  && (i*(i-1)+3) <= size) { // improving the boundary
    int curr_peak=peaks[0]; // we know that there is at least one peak
    int p_index=0; // index in the peaks vector
    int j=1; // the number of flag set
    for( ; j<i; j++ ) {
      while( curr_peak + i > peaks[p_index] ) {
	p_index++;
	if( p_index > pSize-1 )
	  break;
      }
      if( p_index > pSize-1 ) {
	break;
      }
      curr_peak=peaks[p_index];
    }
    if( i==j )
      maxFlag=i;
    i++;
  }
  return maxFlag;
}

int main()
{
  vector<int> A;
  A.push_back(1);
  A.push_back(5);
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
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  std::cout << solution(B) << std::endl;
  vector<int> D;
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  D.push_back(1);
  D.push_back(0);
  std::cout << solution(D) << std::endl;
  return 0;
}
