#include "topcoder.h"

int run(vector<int> card, int score){
  int size = card.size();
  vector < vector <int>> MEMO(size + 1, vector<int>(score + 1, -1));
  const int MOD = 1000000007;

  function <int(int, int)> dfs = [&] (int depth, int s){
    if (depth == size){
      if (s == 0)
        return 1;
      return 0;
    }

    if (MEMO[depth][s] != -1)
      return MEMO[depth][s];
      
    int ret = 0;
    if (s > 0)  // win
      //ret += dfs(depth + 1, s - 1) % MOD;
      ret = dfs(depth + 1, s - 1) % MOD;

    // lose or tie
    ret = ret + dfs(depth + 1, s) % MOD;
    ret = ret % MOD;
    ret = ret + dfs(depth + 1, s) % MOD;
    ret = ret % MOD;
    // ret += dfs(depth + 1, s) % MOD;
    // ret += dfs(depth + 1, s) % MOD;
    return MEMO[depth][s] = ret % MOD;
  };

  return dfs(0, score);
}

int main(){
  P(run({0,1,2}, 2));
  P(run({1,2}, 0));
  P(run({2,2,1,0,0}, 10));
  P(run({0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}, 7));
  P(run({0,1,2,0,1,2,2,1,0} ,8));
}
