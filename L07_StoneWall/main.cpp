#include <iostream>
#include <vector>
#include <stack>

/* StoneWall
 * L07 StoneWall
 */

using namespace std;

int solution(vector<int> &H)
{
  stack<int> piles;
  int counter=0;
  for( auto it=H.begin(); it!=H.end(); it++ ) {
    do {
      if( piles.empty() || piles.top() < *it ) {
	piles.push(*it);
	break;
      }
      if( piles.top() > *it ) {
	piles.pop();
	counter++;
	if( piles.empty() ) {
	  piles.push( *it );
	}
      }
    } while( piles.top() != *it );
  }
  return counter+piles.size();
}


int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(8);
  A.push_back(8);
  A.push_back(5);
  A.push_back(7);
  A.push_back(9);
  A.push_back(8);
  A.push_back(7);
  A.push_back(4);
  A.push_back(8);
  cout << solution(A) << endl;
  return 0;
}
