#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* CountDiv
 * L5 - Ex 1
 */

int solution(int A, int B, int N)
{
  if( A%N!=0 ) {
    A = (A/N +1)*N;
  }
  if( A>B )
    return 0;
  return (B-A)/N+1;
}

int main(int argc, char **argv)
{
  cout << solution(6,11,2);
  return 0;
}
