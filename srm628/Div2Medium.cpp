#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define P(x) cout << #x << " = " << (x) << endl;
#define PS(x)                                                           \
  cout << #x << " = ";                                                  \
  for(char* end = &(x).top(), *begin = end - (x).size(), *i = end; i > begin ; i--) \
    cout << *i << ", ";                                                 \
  cout << endl;
    
// bool dfs(string s, stack<char>& stack){
//   if (s.empty() && stack.empty())
//     return true;

//   bool ret = false;

//   for (int i = 0; i < s.size(); i++){
//     char c = s[i];
//     string substr(s.begin() + i, s.end());

//     if (c == '[' || c == '(' || c == '{')
//       stack.push(c);
//     else if (c == 'X'){
//       if (!stack.empty() && (c == ']' || c == ')' || c == '}')){
//         char c0 = stack.top();
//         stack.pop();
//         ret = max(dfs(substr, stack), ret);
//         stack.push(c0);
//       }
//       string brankets = "({[";
//       for (int i = 0; i < 3; i++){
//         stack.push(brankets[i]);
//         ret = max(dfs(substr, stack), ret);
//         stack.pop();
//       }
//     } else if (c == stack.top())
//       stack.pop();
//   }
//   if (stack.empty())
//     return true;
//   return ret;
// }

bool check(string s){
  stack<char> stack;
  string opens = "{([";
  string closes = "})]";
  for(int i = 0; i < s.size(); i++){
    char c = s[i];
    if (opens.find(c) != string::npos)
      stack.push(c);
    else if(!stack.empty() && c == closes[opens.find(stack.top())]){
      stack.pop();
    } else 
      return false;
    //PS(stack)
  }
  if (stack.empty()) {
    // P(s)
  }
  return stack.empty() ? true : false;
}

string S = "";
string Expr;
int N;
bool dfs(int n){
  //P(S)
  string B = "{[()}]";
  bool ret = false;
  if (n == N)
    return check(S);

  char c = Expr[n];
  if (c == 'X')
    for (int i = 0; i < B.size(); i++){
      string t(S.begin(), S.end());
      S += B[i];
      ret = max(dfs(n+1), ret);
      S = t;
    }
  else{
    S += c;
    ret = max(dfs(n+1), ret);
  }
  return ret;
}

string run(string  expr){
  Expr = expr;
  N = expr.length();
  return dfs(0) ? "POSSIBLE" : "IMPOSSIBLE";
}

int main(){
  P(run("([]{})"));
  P(run("[[]]"));
  P(run("(())[]"));
  P(run("({])"));
  P(run("[]X"));
  P(run("([]X()[()]XX}[])X{{}}]"));
  P(run("([]]()[()]]]}[])({{}}]"))
}
