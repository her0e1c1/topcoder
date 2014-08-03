#include <iostream>
#include <vector>

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

int getRoot(long n, int k){
  // max x s.t. x^k <= n
  

}

int run(long n){
  
}

int main(){

}
