#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* PermCheck
 * Lesson 4 - Ex 3
 */

int solution( vector<int>& A )
{
  int X=A.size();
  vector<int> c(X,0);
  for( vector<int>::iterator i=A.begin(); i!=A.end(); i++ ) {
    if( *i > X )
      return 0;
    if( c[(*i)-1] == 0 ) {
      c[(*i)-1]=1;
    } else {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(4);
  A.push_back(1);
  A.push_back(3);
  A.push_back(2);
  cout << solution(A) << endl;
  A.erase(A.begin(), A.end() );
  A.push_back(4);
  A.push_back(1);
  A.push_back(3);
  cout << solution(A) << endl;
  return 0;
}
