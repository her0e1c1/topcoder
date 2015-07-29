#include <topcoder.h>

/*
 * 二つの円を組み合わせて移動できる距離
 半径r1, r2とし
 [|r1 - r2|, r1 + r2] の間の数値を取ることができる（おそらく）
 3つの場合
 max_R = r1 + r2 + r3
 min_R = ||r1 - r2| - r3|

 一般化
 r1, r2, ... rn
 maxR = sum 1 to n ri
 minR = | ... ||r1 - r2| - r3| ...  - rn|
 上記は間違い
 */


string run(int x, int y, vector<int> jumpLengths)
{
  double dest = sqrt(x * x + y * y);
  int N = jumpLengths.size();

  int maxR = 0;
  REP(i, N) maxR += jumpLengths[i];
  // P(maxR);

  int minR = jumpLengths[0];
  for(int i = 1; i < N; i++){
    minR = abs(minR - jumpLengths[i]);
  }

  // destをsqrtせずに整数で扱うために、以下の判定が正しい
  // minR * minR <= D <= maxR * maxR
  if (minR <= dest && dest <= maxR)
    return "Able";
  return "Not able";
}


int main()
{
  P(run(5,
        4,
        {2, 5}));

  P(run(3,
        4,
        {4}));

  P(run(3,
        4,
        {6}));

  P(run(0,
        1,
        {100, 100}));

  P(run(300,
        400,
        {500}));

  P(run(
        11,
        12,
        {1,2,3,4,5,6,7,8,9,10}
        ));

  P(run(
        11,
        12,
        {1,2,3,4,5,6,7,8,9,100}
        ));

  return 0;
}
