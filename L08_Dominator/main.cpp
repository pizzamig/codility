#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int solution(vector<int> &A )
{
  if( A.empty() ) {
    return -1;
  }
  if( A.size() == 1 ) {
    return 0;
  }
  int leader;
  unsigned int lcounter=0;
  for( auto a: A ) {
    if( lcounter == 0 ) {
      leader=a;
      lcounter=1;
    } else {
      if( leader == a ) {
	lcounter++;
      } else {
	lcounter--;
      }
    }
  }
  lcounter=0;
  int rc=-1;
  for( auto it=A.begin(); it!=A.end(); it++ ) {
    if( *it == leader ) {
      lcounter++;
      if( rc == -1 ) {
	rc=distance(A.begin(), it);
      }
    }
  }
  if( lcounter > A.size()/2 ) {
    return rc;
  } else {
    return -1;
  }
}


int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(0);
  A.push_back(3);
  A.push_back(3);
  A.push_back(4);
  A.push_back(3);
  A.push_back(2);
  A.push_back(3);
  A.push_back(-1);
  A.push_back(3);
  A.push_back(3);
  cout << solution(A) << endl;

}
