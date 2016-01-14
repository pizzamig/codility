#include <iostream>
#include <vector>

using namespace std;

/* MinAvgTwoSlice
 * L5 - Ex 4
 * The idea here, is that we need to look at 2-or-3-size slices only
 * all bigger slices could be "factored" in 2-or-3-size slices
 */

int solution(vector<int> &A )
{
  double minavg=(A[0]+A[1])/2.;
  int min_index=0;
  for( auto i=1; i<A.size()-1; i++ ) {
    double avg=(A[i]+A[i+1])/2.;
    if( avg < minavg ) {
      minavg=avg;
      min_index=i;
    }
  }
  for( auto i=0; i<A.size()-2; i++ ) {
    double avg=(A[i]+A[i+1]+A[i+2])/3.;
    if( avg < minavg ) {
      minavg=avg;
      min_index=i;
    }
  }
  return min_index;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(4);
  A.push_back(2);
  A.push_back(2);
  A.push_back(5);
  A.push_back(1);
  A.push_back(5);
  A.push_back(8);
  int S=solution(A);
  cout << S << endl;
  A.erase(A.begin(),A.end());
  A.push_back(4);
  A.push_back(8);
  A.push_back(-1);
  A.push_back(-10);
  A.push_back(2);
  A.push_back(-10);
  A.push_back(4);
  A.push_back(5);
  A.push_back(8);
  S=solution(A);
  cout << S << endl;
  A.erase(A.begin(),A.end());
  A.push_back(10);
  A.push_back(9);
  A.push_back(8);
  A.push_back(7);
  A.push_back(6);
  A.push_back(5);
  A.push_back(4);
  A.push_back(3);
  A.push_back(2);
  A.push_back(1);
  A.push_back(0);
  A.push_back(-1);
  A.push_back(-2);
  A.push_back(-3);
  S=solution(A);
  cout << S << endl;
  A.erase(A.begin(),A.end());
  A.push_back(4);
  A.push_back(-10);
  A.push_back(0);
  A.push_back(1);
  A.push_back(-10);
  S=solution(A);
  cout << S << endl;
  
  return 0;
}
