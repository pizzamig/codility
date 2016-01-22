#include <iostream>
#include <vector>

using namespace std;

/** Lesson 9: Max Profit
 * 
 */
int solution(vector<int> &A )
{
  int profit=0;
  int profit_prev=0;
  int profit_max=0;
  for( unsigned int i=1; i<A.size(); i++ ) {
    profit=max(0,profit_prev+A[i]-A[i-1]);
    profit_prev=profit;
    profit_max=max(profit_max, profit);
  }
  return profit_max;
}

int main(int argc, char **argv) {
  vector<int> A;
  A.push_back(23171);
  A.push_back(21011);
  A.push_back(21123);
  A.push_back(21366);
  A.push_back(21013);
  A.push_back(21367);
  cout << solution(A) << std::endl;
  return 0;
}
