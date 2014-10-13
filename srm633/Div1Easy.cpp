#include <topcoder.h>

/*
 * 1周期で、Sまで行けるのであれば、
 * 2周期で、0から2Sまでの範囲をカバーできる
 * 最大値がS => 2Sとなるのは、周期が2倍だから
 * 最小値が0となるのは、初め進んだ道のりを同じように戻ればよいから

 * 周期分進んだ後は、一つ一つ計算して求めれば良い
 */

int run(int x, vector<int> jumpLengths)
{
  if (x < 0)
    x = -1 * x;

  int ret = 0;
  int N = jumpLengths.size();
  
  int S = 0;
  for(int y: jumpLengths){
    S += 2 * y;
  }
  // P(S);

  ret = 2 * (x / S) * N;
  int interval = x % S;
  int a = 0;
  int b = S * (x / S);  // == x - x % s

  // P(ret);
  // P(interval);

  if (interval == 0)
    return ret;

  // a<= x <= bであることが必要
  VI j2(2 * N);
  for(int i = 0; i < 2 * N; i++){
    j2[i] = jumpLengths[i % N];
  }

  // P(a);
  // P(b);

  for(int y: j2){
    if (y <= a){
      a = a - y;
    } else if (a < y && y <= b){
      a = 0;
    } else if (b < y){  // b < y
      a = y - b;
    }
    b += y;
    ret++;

  // P(a);
  // P(b);

    if (a <= x && x <= b)
      return ret;
  }

  return -1;
}

int main()
{
  P(run(
        15,
        {1,2,3,4,5,6,7,8,9,10}
        ));

  P(run(
        5,
        {5}
        ));

  P(run(
        1,
        {10}
        ));

  P(run(
        -10,
        {2,3,4,500,6,7,8}
        ));

  P(run(
        -1000000000,
        {1}
        ));

  P(run(
        0,
        {19911120}
        ));

  return 0;
}
