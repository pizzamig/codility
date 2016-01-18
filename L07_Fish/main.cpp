#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* Fish
 * L07
 */

void newFish(stack<int> &stA, stack<int> &stB, int Ai, int Bi )
{
  if( stA.empty() ) {
    stA.push(Ai);
    stB.push(Bi);
    return;
  }
  if( stB.top() <= Bi ) {
    stA.push(Ai);
    stB.push(Bi);
    return;
  }
  if( stA.top() > Ai ) {
    return;
  }
  stA.pop();
  stB.pop();
  newFish(stA, stB, Ai, Bi );
}

int solution(vector<int> &A, vector<int> &B)
{
  stack<int> stA;
  stack<int> stB;
  const unsigned int size=A.size();
  for( unsigned int i=0; i<size; i++ ) {
    newFish(stA, stB, A[i], B[i] );
  }
  return stA.size();
}

int main(int argc, char **argv) {
  vector<int> A;
  vector<int> B;
  A.push_back(4);
  A.push_back(3);
  A.push_back(2);
  A.push_back(1);
  A.push_back(5);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(0);
  B.push_back(0);
  cout << solution(A,B) << endl;
  B.erase(B.begin(), B.end());
  B.push_back(1);
  B.push_back(0);
  B.push_back(1);
  B.push_back(1);
  B.push_back(1);
  cout << solution(A,B) << endl;
  A[3]=6;
  B.erase(B.begin(), B.end());
  B.push_back(1);
  B.push_back(0);
  B.push_back(1);
  B.push_back(0);
  B.push_back(1);
  cout << solution(A,B) << endl;
  return 0;
}
