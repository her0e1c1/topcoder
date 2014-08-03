#include <iostream>
#include <vector>

#define P(x) cout << #x << " = " << x << endl;

using namespace std;

/*
  n = 10^18と非常に大きい数字を扱うのでn^2の計算量では太刀打ちできないのは明らか。（即刻諦める）
  なぜなら、n^2の計算量では、(10 ** 9) ** 2 == 10 ^18 なので、1G回数の計算をしないといけない

  # 10M
  $ time perl -e '$a+=$_ for 1..10**7;'
  perl -e '$a+=$_ for 1..10**7;'  1.12s user 0.00s system 99% cpu 1.127 total
  $ time ruby -e '(1..10**7).inject(:+)'
  ruby -e '(1..10**7).inject(:+)'  1.35s user 0.00s system 99% cpu 1.350 total
  $ time python -c 'sum([i for i in range(10**7)])'
  python -c 'sum([i for i in range(10**7)])'  1.88s user 0.31s system 99% cpu 2.197 total

  # 100M
  $ time perl -e '$a+=$_ for 1..10**8;'
  perl -e '$a+=$_ for 1..10**8;'  11.22s user 0.01s system 99% cpu 11.232 total
 
  つまり1Gの計算は100秒近く掛かる計算となる(MBAでの実行の場合ではあるが)

  なお、log2(x) = 10^7 = log2(2^(10^7)) なので
  x = 2^(10^7) となり、かなり大きい数字まで扱えるようになる

  n^2よりも大きくなるような計算量を考える
  10^18 < 2^60
  10^18 < 15^16
  10^18 < 20^14
  10^18 < 30^13
  当たりを考えると、n^d(n) となる数字は大して多くないことが分かる
 
  2498388559757689 = 49983883 ** 2 であるので
  この問題は49983883を求めないといけない
*/

long pow(int n, int k, long N){
  // Warning: Overflow!!
  long p = 1;
  for (int i = 0; i < k; i++){
    if (p > N)
      return N + 1;
    p *= n;
  }
  return p;
}

int getRoot(long n, int k){
  // max x s.t. x^k <= n
  int lo = 1;
  int hi = n + 1;
  int ret = 0;
  while(true){
    if (lo + 1 >= hi)
      break;
    int mid = (lo + hi) / 2;
    // cout << "mid = " << mid << endl;
    long p = pow(mid, k, n);
    // cout << "p = " << p << endl;
    if (p <= n){
      lo = mid;
      ret = max(ret, mid);
      ret = mid;
    } else {
      hi = mid;
    }
  }
  return pow(ret, k, n) == n ? ret : -1;
}

int dfs(long i, long j, long n){
  if (i * i == n)
    return 1;
  if (i >= j)
    return 0;
  if (n % i == 0)
    return dfs(i + 1, n / i, n) + 2;
  else
    return dfs(i + 1, n / i, n);
}
int countDivisors(int n){
  return dfs(1, n, n);
}

long run(long n){
  long INF = 1L << 60;
  long ret = INF;
  for (int i = 2; i < 63; i++){
    int root = getRoot(n, i);
    // cout << root << " ," << i << endl;
    if (root != -1 && countDivisors(root) == i){
      if (root < ret)
        ret = root;
    }
  }
  return ret == INF ? -1 : ret;
}

int main(){
  P(run(4));
  P(run(10));
  P(run(64));
  P(run(10000));
  P(run(2498388559757689));
  //cout << getRoot(4, 2) << endl;
  //cout << getRoot(10, 2) << endl;
  // cout << getRoot(64, 6) << endl;
  // cout << countDivisors(16) << endl;
  // cout << countDivisors(24) << endl;
  // cout << countDivisors(25) << endl;
}
