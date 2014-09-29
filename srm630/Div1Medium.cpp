#include <topcoder.h>

/*
 * {2 3 1 0} の場合
 * 左から順にa, b, c, dと割り当てれば、SAを満たす文字列となる
 * 一方で、b, aのように順番を逆にするとSAを満たすことができない
 * 残るは、a, aのように連番が続く場合のみを考える。

 * 条件A
 * 1. SA[i] < SA[i + 1] => 別の文字を使用する
 * 2. SA[i] > SA[i + 1] => SAとならない
 * 3. SA[i] == SA[i + 1] => この場合はSAとなる場合とならない場合がある
 * すなわち、SA[i] <= SA[i + 1] であれば、SAを満たす文字列となる
 *
 * 条件Aでは i = 0, 1, 2と順番に次の文字列を指定している

 * A.3について考える
 * 文字列 ****a*****a**** となるが、
 * i が前者の場合、S[i] + 1とS[i + 1] + 1を比較して、S[i] + 1が辞書で小さければよい
 * i が後者の場合も同様（つまり、S[i]とS[i + 1]の大小は関係ない）
 *
 * SA[i] + 1とSA[i + 1] + 1を比較するが、
 * それぞれ、SA[j], SA[k]と対応づける
 * j > k の場合は、****ad****ab**** のような文字列となり、SAを満たさない(例はSA[i]が前者)
 * つまり、SA[i] < SA[+ 1] である必要がある
 * j < k の場合は ****ab****ad**** のような文字列となり、SAを満たす(例はSA[i]が前者)
 * なおj == kとはならない。(別々の箇所を参照しているので、SAも別)

 * 上のは、考えにくい、あらかじめランクをもった文字列を考えるほうがよい
 * 0512436-1
 * 0 => 1 => 2 => と順にみていく
 * (0, 1)の場合、同じ文字が使えるか考える
 * (5, 2)がつづくが、05と12で、0を1よりも小さいものを割り当てる必要がある
 * (1, 2)の場合、(2, 4)となるが、1と2に同じものを割り当ててもよい(はず(後々考える2と4がSAを満たすなら))
 * 端の場合は、(5, 6)のときだが、
 * (1, -1)とみて、別の文字をあたらに使う必要がある
 */

int run(VI sa)
{
  int n = sa.size();
  // 逆関数
  vector<int> rank(n + 1);

  for (int i = 0; i < n; i++){
    rank[sa[i]] = i;
  }
  rank[n] = -1;

  int ret = 1;  // 0番目のものは、何かしら使う必要がある
  for (int i = 0; i < n; i++){
    if (rank[sa[i] + 1] > rank[sa[i + 1] + 1])
      ret++;
  }
  return ret;
}

int main()
{
  P(run({3,0,1,2}));
  P(run({3,2,1,0}));
  P(run({0,1,2,3}));
  P(run({7,4,8,6,1,5,2,9,3,0}));
  P(run({0}));

  return 0;
}
