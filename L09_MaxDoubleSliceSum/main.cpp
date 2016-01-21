#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A )
{
  const unsigned int size=A.size();
  vector<int> upMax(size);
  vector<int> downMax(size);
  upMax[0] = 0;
  upMax[1] = A[1];
  int uMax=upMax[1];
  for( unsigned int i=2; i<size-1; i++ ) {
    upMax[i]=max(uMax+A[i], 0);
    uMax=upMax[i];
  }
  downMax[size-1]=0;
  downMax[size-2]=max(0,A[size-2]);
  int dMax=downMax[size-2];

  for( int i=size-3; i>0; i-- ) {
    downMax[i]=max(dMax+A[i], 0 );
    dMax = downMax[i];
  }
  int maxSlice=0;
  for( unsigned int i=0; i<size-2; i++ ) {
    maxSlice=max(maxSlice, int(upMax[i]+downMax[i+2]));
  }
  return maxSlice;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back( 3 );
  A.push_back( 2 );
  A.push_back( 6 );
  A.push_back( -1 );
  A.push_back( 4 );
  A.push_back( 5 );
  A.push_back( -1 );
  A.push_back( 2 );
  cout << solution(A) << endl;
  vector<int> B;
  B.push_back( 3 );
  B.push_back( 17 );
  B.push_back( 0 );
  B.push_back( 567 );
  cout << solution(B) << endl;
  return 0;
}
