#include <iostream>
#include <vector>

using namespace std;

/** MaxSliceSum
 */

int solution(vector<int> &A )
{
  int sum=A[0];
  int maxi=sum;
  for( unsigned int i=1; i<A.size(); i++ ) {
    sum=max(A[i], sum+A[i]);
    maxi=max(maxi,sum);
  }
  return maxi;
  
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(3);
  A.push_back(2);
  A.push_back(-6);
  A.push_back(4);
  A.push_back(0);
  cout << solution(A) << std::endl;
  return 0;
}
