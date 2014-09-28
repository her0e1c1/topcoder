#include <topcoder.h>

int N;
VI D;
map <int, int> M[101];
const int MOD1 = 1000000007; // (1,000,000,007)
int dfs(int x, int depth)
{
  if (depth == N){
    if (x == 1)
      return 1;
    else
      return 0;
  }

  if (M[depth].count(x) != 0)
    return M[depth][x];

  int ret = 0;
  if (x % D[depth] == 0)
    ret += dfs(x / D[depth], depth + 1) % MOD1;
  ret += dfs(x, depth + 1) % MOD1;
  M[depth][x] = ret;
  return M[depth][x];
}

int run(int goodValue, VI d)
{
  D = d;
  N = d.size();
  // 1の場合は、全て使わない場合が含まれているので、それをのぞく
  return dfs(goodValue, 0) + (goodValue == 1 ? -1 : 0);
}

int main()
{
  P(run(10, {2,3,4,5}));
  P(run(6, {2,3,4,5,6}));
  P(run(1, {1,1,1}));
  P(run(12, {1,2,3,4,5,6,7,8,9,10,11,12}));
  P(run(5, {1,2,3,4}));


  return 0;
}
