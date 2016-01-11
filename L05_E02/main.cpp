#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* PassingCars
 * L5 - Ex 2
 */

int solution(vector<int> &A )
{
  long globalCounter=0;
  int loopCounter=0;
  int multiplier=0;
  for( auto car: A ) {
    if( car == 1 ) {
      loopCounter++;
    } else {
      globalCounter += loopCounter*multiplier;
      loopCounter = 0;
      multiplier++;
      if( globalCounter > 1000000000 || globalCounter < 0)
	return -1;
    }
  }
  if( A.back() == 1 ) {
    globalCounter += loopCounter*multiplier;
      if( globalCounter > 1000000000 || globalCounter < 0)
	return -1;
  }
  return (int)globalCounter;
}

int main(int argc, char **argv)
{
  vector<int> A;
  A.push_back(0);
  A.push_back(1);
  A.push_back(0);
  A.push_back(1);
  A.push_back(1);
  A.push_back(0);
  A.push_back(1);
  int S=solution(A);
  cout << S << endl;
  return 0;
}
