#include <iostream>
#include <vector>
#include <algorithm>

/* NumberOfDiscIntersections
 * L6 - Ex 4
 */
using namespace std;

int solution(vector<int> &A )
{
  const unsigned int size=A.size();
  vector<long> L(size);
  vector<long> U(size);
  for( long i=0; i<(long)size; i++) {
    L[i]=i-A[i];
    U[i]=i+A[i];
  }
  sort(L.begin(), L.end());
  sort(U.begin(), U.end());
  unsigned int li=0; // low index
  unsigned int ui=0; // up index
  long intersections=0;
  for(; ui<size;ui++ ) {
    while( li < size && L[li] <= U[ui] )
      li++;
    intersections += li-ui-1;
    if( intersections > 10000000 )
      return -1;
  }
  return intersections;
}


int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(1);
  A.push_back(5);
  A.push_back(2);
  A.push_back(1);
  A.push_back(4);
  A.push_back(0);
  cout << solution(A) << endl;
  return 0;
}
