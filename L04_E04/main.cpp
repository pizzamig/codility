#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* MaxCounters
 * L4 - Ex 4
 */

vector<int> solution(int N, vector<int> &A )
{
  vector<int> c(N,0);
  int max=0;
  int reset_value=0;
  for( vector<int>::iterator it=A.begin(); it!=A.end(); it++) {
    if( *it < 1 )
      continue;
    if( *it > N+1)
      continue;
    if( *it < N+1 ) {
      int idx=(*it)-1;
      if( c[ idx ] < reset_value ) {
	c[idx] = reset_value+1;
      } else {
	c[ idx ]++;
      }
      if( c[ idx ] > max ) {
	max=c[ idx ];
      }
    } else {
      reset_value=max;
    }
  }
  for( vector<int>::iterator it=c.begin(); it!=c.end(); it++) {
    if( *it < reset_value ) {
      *it=reset_value;
    }
  }
  return c;
}

int main(int argc, char **argv)
{
  vector<int> A;
  A.push_back(3);
  A.push_back(4);
  A.push_back(4);
  A.push_back(6);
  A.push_back(1);
  A.push_back(4);
  A.push_back(4);
  vector<int> S=solution(5,A);
  for( vector<int>::iterator it=S.begin(); it!=S.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
