#include <iostream>
#include <vector>
#include <algorithm>

/* Distinct
 * L6 - Ex 1
 */
using namespace std;

int solution(vector<int> &A )
{
  if( A.empty() ) return 0;
  sort(A.begin(),A.end());
  int dist=1;
  for( unsigned int i=1; i<A.size(); i++ ) {
    if( A[i]!=A[i-1] )
      dist++;
  }
  return dist;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(2);
  A.push_back(1);
  A.push_back(1);
  A.push_back(2);
  A.push_back(3);
  A.push_back(1);
  cout << solution(A) << endl;
  return 0;
}
