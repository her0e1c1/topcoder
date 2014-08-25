#include <topcoder.h>

// 1, 2 ... N
string run(int k, VI a){
  int N = a.size();
  vector<bool> MEMO(N + 1, false);

  for (int i = 1; i <= N; i++){
    for (int j = 0; j < N; j++){
      if (MEMO[j])
        continue;

      // 条件 n = i + 1 (mod k) and n <= i + 1
      int n = a[j];
      if (n <= i && n % k == i % k){
        MEMO[j] = true;
        break;
      }
    }
  }

  for (int j = 0; j < N; j++){
    if (!MEMO[j])
      return "IMPOSSIBLE";
  }
  return "POSSIBLE";
}

int main(){
  V(int, v0, 1,2,4,3);
  P(run(3, v0));

  V(int, v1, 2,2);
  P(run(5, v1));

  V(int, v2, 1,1,1,1,1,1,1,1);
  P(run(1, v2));

  V(int, v3, 5,3,3,2,1);
  P(run(2, v3));

  V(int, v4, 1,2,3,1,4,5,6,7,9,8);
  P(run(9, v4));

  V(int, v5, 1,1,1,1,1,1,2,2,2,2,2,2);
  P(run(2, v5));

  V(int, v6, 1);
  P(run(1, v6));

}
