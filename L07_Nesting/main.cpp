#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string &S)
{
  stack<char> ps; // parenthesis' stack
  for( auto c: S ) {
    switch (c) {
      case '(':
	ps.push(c);
	break;
      case ')':
	if( ps.empty() ) {
	  return 0;
	}
	ps.pop();
	break;
      default:
	return 0;
    }
  }
  if( ps.empty() ) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char **argv) {
  string S("()()()()");
  string S2("()()()()(");
  string S3("()()()())");
  string S4("))((");
  
  cout << solution(S) << endl;
  cout << solution(S2) << endl;
  cout << solution(S3) << endl;
  cout << solution(S4) << endl;
  
  return 0;
}
