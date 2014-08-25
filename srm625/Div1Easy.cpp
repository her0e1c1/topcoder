#include <topcoder.h>

string WORD;
int N;

// 基本的な方針は、n!/p!q!r! の計算
// 回文は、(n/2)!/(p/2)!(q/2)!(r/2)! 通りある

/*
三角
    1
   1 1
  1 2 1
 1 3 3 1

nC0 = 1
nCn = 1
nCr = n-1Cr + n-1Cr-1
*/
int C(int n, int r){
  if (r == 0 || r == n)
    return 1;
  else
    return C(n - 1, r) + C(n - 1, r - 1);
}

// WARNING: 
// 奇数と偶数の場合に分けて考える
// 一つにまとめられる? n/2 を切り下げることで

// n! の計算はすぐにオーバーフローするので注意
double run(string word){
  WORD = word;
  N = word.size();
  int sum2 = N;
  set<char> s;
  REP(i, N) s.insert(word[i]);

  // N!の計算
  vector<double> PN(50, 1);
  for(int i = 2; i < PN.size(); i++){
    PN[i] = i * PN[i - 1];
  }

  set<char>::iterator it;
  int n_odd = 0;
  int sum1 = 0;
  double ret = 1;
  for (it = s.begin(); it != s.end(); it++){
    char c = *it;
    int n = count(word.begin(), word.end(), c);
    if (n % 2 != 0){
      n_odd++;
      if (n_odd >= 2)
        return 0;
      sum1++;
    } else {
      ret *= PN[n];
      ret /= PN[n/2];
      sum1 += n/2;
    }
  }
  return ret = ret * PN[sum1] / PN[sum2];

  // 最後にこれを評価することで、nが正しい場合意外は排除できる
  // (odd > 1) || (odd != n % 2)
}

int main(){
  P(run("haha"));
  P(run("xxxxy"));
  P(run("xxxx"));
  P(run("abcde"));
  P(run("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"));
}
