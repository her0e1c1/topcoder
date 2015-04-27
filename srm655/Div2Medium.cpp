#include <topcoder.h>

// x <= y
// some k s.t 2^k <= x, y < 2^(k + 1)
int fold(int folded, int size){
  int cnt = 0;
  while((pow(2, cnt) * folded) < size){
    cnt++;
  }
  return cnt;
}

int run(int W, int H, int A)
{
  vector<int> P;
  // 素因数を求める
  // たかだか100K回
  for(int i = 1; i <= A; i++)
    if(A % i == 0){
      P.push_back(i);
    }
  int mi = min(W, H);
  int ma = max(W, H);

  int ans = INF;
  // Pは素因数の結果なので要素数は少ない
    for(int i = 0; i < P.size(); i++){
    // x <= yが成立
    int x = P[i];
    int y = A / x;
    // 折り畳めることが可能な条件
    if (x <= mi && y <= ma){
      int times = fold(x, mi) + fold(y, ma);
      // P(times)P(x)P(y)
      ans = min(ans, times);
    }
  }

  return ans == INF ? -1 : ans;
}

int main()
{
  P(run(5, 3, 12));
  P(run(2,2,3));
  P(run(4,4,1));
  P(run(127,129,72));
  P(run(1, 100000, 100000));
  P(run(1,1,2));

  return 0;
}
