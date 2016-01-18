#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int solution(vector<int> &A )
{
  if( A.empty() ) {
    return 0;
  }
  if( A.size() == 1 ) {
    return 0;
  }
  // looking for the leader
  int leader;
  unsigned int lcounter=0;
  for( auto a: A ) {
    if( lcounter == 0 ) {
      leader=a;
      lcounter=1;
    } else {
      if( leader == a ) {
	lcounter++;
      } else {
	lcounter--;
      }
    }
  }
  lcounter=0;
  unsigned int const size=A.size();
  vector<unsigned int> ps(size); // prefix_sum: how many leader encountered so far
  for( unsigned int i=0; i<size; i++) {
    if( A[i] == leader ) {
      lcounter++;
    }
    ps[i]=lcounter;
  }
  unsigned int equiCounter=0;
  // evaluating all the splits
  for( unsigned int s=1; s<size; s++ ) { // s is the split point, the begin of the right partition
    // left partition
    unsigned int lc=ps[s-1];
    if( lc <= s/2 ) {
      // the leader is not the left partition leader, skipping
      continue;
    }
    unsigned int rc=ps[size-1]-lc;
    if( rc <= (size-s)/2 ) {
      // the leader is not the right partition leader, skipping
      continue;
    }
    equiCounter++;
  }
  return equiCounter;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(4);
  A.push_back(3);
  A.push_back(4);
  A.push_back(4);
  A.push_back(4);
  A.push_back(2);
  cout << solution(A) << endl;
  return 0;
}
