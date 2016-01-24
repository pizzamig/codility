#include <iostream>
#include <vector>

using namespace std;

inline bool isSemiprime(int n, const vector<int> &F)
{
  if( n>=F.size() || n<=3)
    return false;
  int f1=F[n]; // first factor
  if( f1 == 0 )
    return false;
  if( F[n/f1] == 0 ) 
    return true;
  return false;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q )
{
  vector<int> F(N+1,0); // F contains the smallest factor
  int i=2;
  while(i*i <= N) {
    if( F[i] == 0 ) { // if i is prime
      int k=i+i;
      while( k<= N) { // boundary check
	if( F[k] == 0 ) {
	  F[k]=i; // save the smallest factor
	}
	k+=i;
      }
    }
    i++;
  }
  vector<int> S(N+1); // S contains the number of semiprimes encountered
  S[0] = 0;
  for( int j=1; j<N+1; j++) {
    S[j]=S[j-1];
    if( isSemiprime(j,F) ) {
      S[j]++;
    }
  }
  const unsigned int qsize=P.size();
  vector<int> R(qsize);
  for( int j=0; j<qsize; j++ ) {
    R[j]=S[Q[j]]-S[P[j]-1];
  }
  return R;
}

int main(int argc, char **argv) {
  vector<int> P;
  vector<int> Q;
  P.push_back(1);
  Q.push_back(26);
  P.push_back(4);
  Q.push_back(10);
  P.push_back(16);
  Q.push_back(20);
  auto R=solution(26,P,Q);
  for ( auto r: R )
    cout << r << endl;
  return 0;
}
