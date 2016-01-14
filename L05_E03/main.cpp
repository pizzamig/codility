#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

/* GemonicRangeQuery
 * L5 - Ex 3
 */

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
  int A=-1;
  int C=-1;
  int G=-1;
  vector<int> sx(S.size());
  vector<int> val(S.size());
  for( unsigned long i=0; i<S.size(); i++ ) {
    switch( S[i] ) {
      case 'A':
	val[i]=1;
	A=i;
	sx[i]=-1;
	break;
      case 'C':
	val[i]=2;
	C=i;
	sx[i]=A;
	break;
      case 'G':
	val[i]=3;
	G=i;
	sx[i]=max(A,C);
	break;
      case 'T':
	val[i]=4;
	sx[i]=max(A,max(C,G));
	break;
    }
  }
  A=C=G=S.size();
//   C=A;
//   G=A;
  vector<int> dx(S.size());
  for( long i=S.size()-1; i>=0; i-- ) {
    switch( S[i] ) {
      case 'A':
	A=i;
	dx[i]=S.size();
	break;
      case 'C':
	C=i;
	dx[i]=A;
	break;
      case 'G':
	G=i;
	dx[i]=min(A,C);
	break;
      case 'T':
	dx[i]=min(A,min(C,G));
	break;
    }
  }
  vector<int> sol(P.size());
  for( unsigned long i=0; i<P.size(); i++ ) {
    if( P[i] == Q[i] ) {
      sol[i]=val[P[i]];
      continue;
    }
    int min_P=val[P[i]];
    int min_Q=val[Q[i]];
    // minimize P
    int pos=P[i];
    while( true ) {
      if( min_P == 1 )
	break;
      if( dx[pos] > Q[i] )
	break;
      pos=dx[pos];
      min_P=val[pos];
    }
    // minimize Q
    pos=Q[i];
    while( true ) {
      if( min_Q == 1 )
	break;
      if( sx[pos] < P[i] )
	break;
      pos=sx[pos];
      min_Q=val[pos];
    }
    sol[i]=min(min_P, min_Q);
  }
  return sol;
}

int main(int argc, char **argv) {
  string S("CAGCCTA");
  vector<int> P;
  vector<int> Q;
  P.push_back(2);
  Q.push_back(4);
  P.push_back(5);
  Q.push_back(5);
  P.push_back(0);
  Q.push_back(6);
  vector<int> Sol;
  Sol=solution(S,P,Q);
  for( auto s: Sol ) {
    cout << s << endl;
  }
//   std::cout << "Hello, world!" << std::endl;
  return 0;
}
