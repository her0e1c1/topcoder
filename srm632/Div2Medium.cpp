#include <topcoder.h>

/*
 * 0埋めされるので、おそらく2^nの倍数でないといけない?
 * 全ての組み合わせは、せいぜい、sum nCr 程度

 * 長さ1, 2は必ずgeomitric seqとなる
 * 次も同じ値のときは、r = 1でないといけない

 * 偶数をかけると0が一つは増える
 * 奇数をかけると N * 1の場合と結果がおなじ

 * 奇数は0をずらさない
 * 2の倍数は、0を一つずらす
 * 4の倍数は、0を2つずらす
 * Nの倍数は、0をnずらす

 * よって、間隔が同じでないといけない(はず)
 * シーケンスは、連番でないといけないので、i, jの２点でよい
 */

VI D;
int N;
vector<bool> MEMO;
/*
 * 000
 * 001
 * 010
 * 100
 * 011
 * 101
 * 110
 * 111
 */

int
run(VI d)
{
  D = d;
  N = d.size();
  
  int ret = 0;
  for(int i = 0; i < N; i++){
    for(int j = i; j < N; j++){
      if (i == j || j - i == 1){
        // P(i);
        // P(j);
        ret++;
        continue;
      }
      int d1 = d[i + 1] - d[i];
      bool flag = false;
      for(int k = i; k < j; k++){
        int d2 = d[k + 1] - d[k];
        if (d1 != d2){
          flag = true;
        }
      }
      if (! flag)
        ret++;
    }
  }

  return ret;
}

int
main()
{
  P(run({0,1,2}));
  P(run({1,2,4}));
  P(run({3,2,1,0}));
  P(run({1,2,4,8,16}));
  P(run({1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}));
  return 0;
}
