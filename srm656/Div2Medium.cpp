#include "topcoder.h"


double run(vector<int> d){
  int size = d.size();
  int counter = 0;
  vector<int> MEMO(size);
  vector<bool> VIS(size);

  P(size);
  function <int(int)> dfs = [&] (int depth) {
    if (depth == size){
      int smallest = size;
      int s = 0;
      counter++;
      FOR(i, 0, size){
        if (MEMO[i] > smallest)
          return s;
        s += d[MEMO[i]];
        smallest = MEMO[i];
      }
      return s;
    }

    int rv = 0;
    FOR(i, 0, size){
      if (VIS[i])
        continue;
      VIS[i] = true;
      MEMO[depth] = i;
      rv += dfs(depth + 1);
      VIS[i] = false;
    }
    return rv;
  };
  
  double ans = dfs(0) / (double)counter;
  return ans;
}

int main(){
  P(run({1,1,1}));
  P(run({10,20}));
  P(run({3,6,10,9,2}));
  P(run({10,9,8,7,6,5,4,3,2,1}));
  P(run({1,2,3,4,5,6,7,8,9,10}));
  P(run({1,1,1,1,1,1,1,1,1,1}));
}
