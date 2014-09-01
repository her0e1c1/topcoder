#include <topcoder.h>

/*
 * 求める解は、行列のrank
 * つまり、1次独立なベクトルを求める
 * ただし、普通の行列計算と異なるのは、
 * 掃き出し法がxorを用いるところ(そもそもxorは線形性がある?)
 *
 * 1100 x 1010 = 0110 (mod 2) などが成立するが
 * f(ax + by)  = af(x) + bf(y)
 * xorが線形性をもつことのの証明が必要
 *
 * 例)
 * 0から7までの数字は、001, 010, 100の3つで表現できる
 * 000 = 001 x 001 = 000
 * 100, 010, 001はそのまま用いる
 * 110 = 100 x 010
 * 011 = 010 x 001
 * 101 = 100 x 001
 * 111 = 110 x 001
 */

// 最大bitを求める
int
get_max_bit(int n)
{
  int i = 0;
  while ((1 << (i + 1)) < n)
    i++;
  return 1 << i;
}

int
run(VI colors)
{
  int size = colors.size();
  for (int i = 0; i < size; i++){
    sort(RALL(colors));
    //PE(colors);
    int max_bit = get_max_bit(colors[i]);
    for (int k = i + 1; k < size; k++){
      int c = colors[k];
        // P(c);
        // P(max_bit) ;
      if (c >= max_bit){
        // P(i);
        // P(k);
        colors[k] ^= colors[i];
      }
    }
  }
  int result = 0;
  for (int i = 0; i < size; i++){
    if (colors[i] > 0)
      result++;
  }
  return result;
}

int
main()
{
  P(get_max_bit(14));
  V(int, v1, 1, 7, 3);
  P(run(v1));

  V(int, v2, 10);
  P(run(v2));

  V(int, v3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  P(run(v3));

  V(int, v4, 534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151);
  P(run(v4));

  V(int, v5, 4, 8, 16, 32, 64, 128, 256, 512, 1024);
  P(run(v5));

  return 0;
}
