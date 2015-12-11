#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int solution( vector<int>& A )
{
  int X=A.size();
  vector<int> c(X,0);
  for( vector<int>::iterator it = A.begin(); it!=A.end(); it++ ) {
    if( *it <= 0 )
      continue;
    if( *it > X )
      continue;
    c[(*it)-1]=1;
  }
  vector<int>::iterator f = find(c.begin(), c.end(), 0);
  if (f == c.end() ) {
    return X+1;
  } else {
    return distance(c.begin(), f)+1;
  }
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(1);
  A.push_back(3);
  A.push_back(6);
  A.push_back(4);
  A.push_back(1);
  A.push_back(2);
  cout << solution(A) << endl;
  A.erase(A.begin(), A.end() );
  A.push_back(1);
  cout << solution(A) << endl;
  return 0;
}
