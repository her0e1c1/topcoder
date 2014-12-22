#include <topcoder.h>

int MOD1 = 1000000007;
using ll = long long;

int run(vector<int> size, int maxSizeSum){
  int N = size.size();
  if (!N) return 1;
  auto m = min_element(size.begin(), size.end());
  int idx = distance(size.begin(), m);
  ll cnt = 1;
  for (int i = idx+1; i < N && size[i]+*m <= maxSizeSum; i++) cnt++;
  for (int i = idx-1; i >= 0 && size[i]+*m <= maxSizeSum; i--) cnt++;
  size.erase(m);
  return (cnt * run(size, maxSizeSum)) % MOD1;
}

int main(){
  P(run({1, 2, 3},
        3));

  P(run({1, 2, 3},
        1000));

  P(run({1, 2, 3},
        4));

  P(run({1,1,1,1,1,1,1,1,1,1,1,1,1},
        2));

  P(run({2,4,6,1,3,5},
        8));

  P(run({1000000000},
        1000000000));
}
