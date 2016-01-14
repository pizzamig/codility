#include <iostream>
#include <vector>
#include <algorithm>

/* Triangle
 * L6 - Ex 3
 */
using namespace std;

int solution(vector<int> &A )
{
  if( A.size() < 3 ) return 0;
  sort( A.begin(), A.end());
  for( auto it=A.begin();it!=A.end()-2;it++) {
    if( (long)*it + (long)*(it+1) > (long)*(it+2) ) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(10);
  A.push_back(2);
  A.push_back(5);
  A.push_back(1);
  A.push_back(8);
  A.push_back(20);
  A.push_back(-7);
  cout << solution(A) << endl;
  return 0;
}
