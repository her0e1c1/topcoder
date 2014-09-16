#include <topcoder.h>

/*
 * currentは、一つ前のおいた場所を表す
 * A) 左側に十分なスペースがある場合は、(current + 1 <= p - time)
 * 左端から(current + 1)埋めていく(2 of Bの場合は無効状態)
 *
 * B) そうでない場合は、
 * 1. current + 1から埋めていく
 * 2. currentに、重ねてのせる(case 1 of C)
 *
 * C) 右端が十分に確保できない場合(current == p + time)
 * 1. 残りの全てを右端に重ねる (current = p + time)
 *    集約状態になったので、結果をインクリメント
 *
 */

int
run(VI position, VI count, int time)
{
  int N = position.size();
  vector<pair<int, int> > V;
  REP(i, N) V.push_back(make_pair(position[i], count[i]));
  sort(ALL(V));

  int current = -1 << 31;
  int counter = 0;
  int flag = false;  // true if you can put one in the same position (1 of C)
  REP(i, N){
    int p = V[i].first;
    int n = V[i].second;
    REP(k, n){
      // 左端の場合
      int next;
      if (current + 1 <= p - time){
        flag = false;
        next = p - time;
      } else {
        if (flag)
          break;
        next = current + 1;
      }
      // 右端の場合
      if (current >= p + time){
        current = p + time;
        flag = true;
        counter++;
        break;
      }
      current = next;
    }
  }

  return counter;
}

int
main()
{
  P(run({0}, {7}, 3));
  P(run({0}, {6}, 2));
  P(run({4, 7, 47}, {4, 7, 4}, 1));
  P(run({3, 0, 7, 10}, {3, 7, 4, 5}, 2));
  P(run({-5, 0, 7}, {47, 85, 10}, 6));
  P(run({-8, 12, -15, -20, 17, -5, 7, 10}, {20, 10, 7, 9, 2, 8, 11, 10}, 2));

  return 0;
}
