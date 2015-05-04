#include "topcoder.h"

int run(vector<int> a){
  int ans = 0;
  int size = a.size();
  function <int(int, int, int)> dfs = [&] (int s, int x, int c){
    if (a[s] == x && x == c){
      ans++;
      if (s == size - 1)
        return ans;
      else
        return dfs(s + 1, a[s + 1], 1);
    } else {
      if (a[s] == x && c < x){
        if (s == size -1)
          return -1;
        return dfs(s + 1, x , c + 1);
      } else
        return -1;
    }
  };
  return dfs(0, a[0], 1);
}

int main(){
  P(run({2,2,3,3,3}));
  P(run({1,1,1,1,1}));
  P(run({3,3}));
  P(run({4,4,4,4,1,1,2,2,3,3,3}));
  P(run({2,1,2,2,1,2}));
  P(run({2,2,3,3,3,2,1,4,4,4,4}));
  
}  
