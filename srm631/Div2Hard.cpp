#include <topcoder.h>

/*
 * 再帰でとく、0 or 1 or 2 使うでok

 * 制約
 * 使えるビットは0から２回まで
 * １桁大きい位のbitを使用している場合は、その手前のbitに分割できない
 * はじめの数字を2^n の和で表す必要がある

 * データの持ち方を考える
 * vecter<int> 0 or 1 or 2までが上限
 * vecter<bool> A, B; (こちらの方が制限があっていい)
 * long A, B; でよさそう
 * A >= B の制約をつける(使ったコインを保持するだけ)
 * 分割した後が重複しないか、把握する必要ある(うまく分割して考慮しない方向がよさそう)

 * Nは必ず二進数の何かしらで表現できる
 * 6 = 110
 *   = 100 + 010 (4 + 2)
 *   = 100 + 001 + 001 (4 + 1 + 1)
 *   = 010 + 010 + 001 + 001 (2 + 2 + 1 + 1)

 * 7 = 111
 *   = 100 + 010 + 001

 * 20 = 10100
      = 10000 + 00100 (16 + 4)
      = 01000 + 01000 + 00100 (8 + 8 + 4)
      = 01000 + 01000 + 00010 + 00010 (8 + 8 + 2 + 2)
      = 01000 + 01000 + 00010 + 00001 + 00001 (8 + 8 + 2 + 1 + 1)
      = 10000 + 00010 + 00010 (16 + 2 + 2)
      = 10000 + 00010 + 00001 + 00001  (16 + 2 + 1 + 1)

 * 16 = 10000 + 00000 (16 + 0)
 *    = 01000 + 01000 (8 + 8)
 *    = 01000 + 00100 + 00100 (8 + 4 + 4)
 *    = 01000 + 00100 + 00010 + 00010 (8 + 4 + 2 + 2)
 *    = 01000 + 00100 + 00010 + 00001 + 00001 (8 + 4 + 2 + 1 + 1)
 */

// long long A, B;
// long long RET = 0;

// void
// dfs(){
//   for (int i = 0; (1 << i) <= A; i++ ){
//     long long bit = 1 << i;
//     long long next = 1 << (i + 1);
//     if ((A & bit) == 0 && (B & bit) == 0) {
//       if ((A & next) > 0 && A >= B) {
//         A -= next;
//         A += bit;
//         B += bit;
//         // P(A);
//         // P(B);
//         RET++;
//         dfs();
//         A += next;
//         A -= bit;
//         B -= bit;
//       }
//     }
//   }
// }

typedef unsigned long long UL;
map <pair<UL, int>, UL> M;

UL
dfs(long long n, int index)  // base 0
{
  if (n == 0)
    return 1;
  if (index < 0 || n < 0 || n > ((UL)1 << (index + 3)))
    return 0;
  // Memo
  if (M.find(make_pair(n, index)) != M.end())
    return M[make_pair(n, index)];

  UL next0 = n;  // 0枚使う
  UL next1 = n - ((UL)1 << index);  // 一枚使う
  UL next2 = n - ((UL)1 << (index + 1));  // 二枚使う

  long long ret = 0;
  ret += dfs(next0, index - 1);
  ret += dfs(next1, index - 1);
  ret += dfs(next2, index - 1);

  M.insert(make_pair(make_pair(n, index), ret));

  return ret;
}

long long
run(long long N){
  long long sum = 0;
  return dfs(N, 60);
}

int
main()
{
  P(run(1));
  P(run(6));
  P(run(47));
  P(run(256));
  P(run(8489289));
  return 0;
}
