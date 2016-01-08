#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* FrogRiverOne
 * Lesson 4 - Ex 2
 */
int solution( int X, vector<int>& A )
{
  vector<int> c(X,0);
  const int goal= (X+1)*(X/2) + (X%2==1?((X+1)/2):0); // the sum of X elements
  int sum=0;
  for( vector<int>::iterator i=A.begin(); i!=A.end(); i++ ) {
    if( *i > X )
      continue;
    if ( c[(*i)-1]==0) {
      c[(*i)-1]=1;
      sum+=*i; // summing only once
      if( sum == goal ) {
	return distance(A.begin(),i);
      }
    }
  }
  return -1;
}

int main(int argc, char **argv)
{
  vector<int> A;
  A.push_back(1);
  A.push_back(3);
  A.push_back(1);
  A.push_back(4);
  A.push_back(2);
  A.push_back(3);
  A.push_back(5);
  A.push_back(4);
  cout << solution(5,A) << endl;
  A.erase(A.begin(), A.end() );
  A.push_back(1);
  cout << solution(1,A) << endl;
  return 0;
}
