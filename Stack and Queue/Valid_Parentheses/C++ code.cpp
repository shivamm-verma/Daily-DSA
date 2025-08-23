#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
  stack<char> st;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      st.push(s[i]);
    }
    else if (!st.empty() && ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')))
    {
      st.pop();
    }
    else
    {
      return false;
    }
  }
  if (!st.empty())
  {
    return false;
  }
  return true;
}

int main()
{
  string s;
  s = "{[()]()}";
  cout << isValid(s)<<endl; // output : 1 
  s = "{(([)])}";
  cout << isValid(s)<<endl; // output : 0 
  return 0;
}