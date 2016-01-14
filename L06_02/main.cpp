#include <iostream>
#include <vector>
#include <algorithm>

/* MaxProductOfThree
 * L6 - Ex 2
 */
using namespace std;

int solution(vector<int> &A )
{
  if( A.empty() ) return 0;
  if( A.size() == 1 ) return A[0];
  if( A.size() == 2 ) return A[0]*A[1];
  int max1=min( A[0], A[1] );
  int max2=max( A[0], A[1] );
  int max3;
  if( A[2]>max2 ) {
    max3=A[2];
  } else {
    max3=max2;
    if( A[2]>max1 ) {
      max2 = A[2];
    } else {
      max2 = max1;
      max1 = A[2];
    }
  }
  int neg1=min(0,max1); // highest negative
  int neg2=min(0,max2); // second highest negative
  
  for( auto n=A.begin()+3; n!=A.end(); n++ ) {
    if( *n > max3 ) {
      max1=max2;
      max2=max3;
      max3 = *n;
    } else {
      if( *n > max2 ) {
	max1=max2;
	max2=*n;
      } else {
	if( *n > max1 ) {
	  max1=*n;
	}
      }
    }
    if( *n < 0 ) {
      if( *n < neg1 ) {
	neg2=neg1;
	neg1=*n;
      } else {
	if( *n < neg2 ) {
	  neg2=*n;
	}
      }
    }
  }
  return max(max1*max2*max3, neg1*neg2*max3);
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(-3);
  A.push_back(1);
  A.push_back(2);
  A.push_back(-2);
  A.push_back(5);
  A.push_back(6);
  A.push_back(-7);
  cout << solution(A) << endl;
  return 0;
}
