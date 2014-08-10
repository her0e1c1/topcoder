#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define P(x) cout << #x << " = " << (x) << endl;


bool dfs(string s, vector<char>& stack){
  for (int i = 0; i < s.size(); i++){
    var c = s[i];
    if (c == '[' || c == '(' || c == '{')
      stack.push_back(c);
    else if (c == stack.back())
      stack.pop();
    else if (c == 'X'){
      if (!stack.empty() && (c == ']' || c == ')' || c == '}'))
        stack.pop();
      
    }
  }
}

string run(string  expr){
  vector<char> stack;
  for (int i = 0; i < expr.size(); i++){
    var c = expr[i];
    if (c == '[' || c == '(' || c == '{')
      stack.push_back(c);
    else if (c == stack.back())
      stack.pop();
    
  }
}

int main(){

}
