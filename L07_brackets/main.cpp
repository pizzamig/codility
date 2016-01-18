#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* Brackets
 * L07
 */
int solution(string &S)
{
  stack<char> st;
  for( auto c: S ) {
    switch (c) {
      case '{':
      case '[':
      case '(':
	st.push(c);
	break;
      case ')':
	if( st.empty() || st.top() != '(' )
	  return 0;
	st.pop();
	break;
      case ']':
	if( st.empty() || st.top() != '[' )
	  return 0;
	st.pop();
	break;
      case '}':
	if( st.empty() || st.top() !=  '{' )
	  return 0;
	st.pop();
	break;
      default:
	return 0;
    }
  }
  if( ! st.empty() ) return 0;
  return 1;
}

int main(int argc, char **argv) {
  string S1("{[()()]}");
  string S2("{[(])()}");
  string S3(")(");
  string S4("{{{{");
  cout << solution(S1) << endl;
  cout << solution(S2) << endl;
  cout << solution(S3) << endl;
  cout << solution(S4) << endl;
  return 0;
}
