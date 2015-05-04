#include "topcoder.h"

string run(vector<int> a){
  int size = a.size();
  vector<int> MEMO(size, -1);

  function <int(int)> dfs = [&] (int depth){
    if (depth == size)
      return 1;

    if (MEMO[depth] != -1)
      return MEMO[depth];

    int current = a[depth];
    int ret = 0;
    if (current == 0){
      for (int i = 1; i <= 100; i++){
        // 配列の幅を超えた
        if (i + depth > size)
          break;

        bool ok = true;
        // 途中の発言と矛盾するか?
        for (int j = depth; j < depth + i; j++){
          if (! (a[j] == i || a[j] == 0)){
            // P(depth)P(i)P(j)P(a[j])
            ok = false;
          }
        }
        if (ok)
          ret += dfs(depth + i);
      }
    } else {
      bool ok = true;
      // P(current);
      for (int i = 0; i < current; i++){
        if (! (a[depth + i] == current || a[depth + i] == 0)){
          //P(depth)P(i)P(a[depth + i])
          ok = false;
        }
      }
      if (ok){
        if (depth + current <= size)
          ret = dfs(depth + current);
      }
    }
    return MEMO[depth] = ret;
  };

  int ans = dfs(0);
  P(ans);
  return ans == 1 ? "Sufficient" : "Insufficient";
}

int main(){
  P(run({0,2,3,0,0}));
  P(run({0,2,0}));
  P(run({0,3,0,0,3,0}));
  P(run({0,0,3,3,0,0}));
  P(run({2,2,0,2,2}));
}
