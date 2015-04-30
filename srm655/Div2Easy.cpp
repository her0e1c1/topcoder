#include "topcoder.h"

string run(vector<string> board){
  int M = board.size();
  int N = board[0].size();

  function<bool(int, char)> dfs = [&] (int x, char prev){
    if (x == M)
      return true;
    char fisrt = 'A';
    for(int y = 0; y < N; y++){
      char curr = prev == 'B' ? 'W' : 'B';
      if (y == 0)
        fisrt = curr;
      char b = board[x][y];
      if (curr == b || '?' == b){
        prev = curr;
      } else{
        // P(x) P(y) P(curr) P(prev)
        return false;
      }
    }
    if (fisrt != 'A')
      return dfs(x + 1, fisrt);
    else{
      P("warn");
      return false;
    }
  };

  if(dfs(0, 'B') || dfs(0, 'W'))
    return "Possible";
  else
    return "Impossible";
}


int main(){

  P(run({"W?W",
          "??B",
          "???"}));
  P(run({"W??W"}));
  P(run({"??"}));
  P(run({"W???",
          "??B?",
          "W???",
          "???W"}));
  P(run({"W???",
          "??B?",
          "W???",
          "?B?W"}));
  P(run({"B"}));
  

}
