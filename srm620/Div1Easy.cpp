#include <iostream>
#include <set>
#include <utility>

using namespace std;
#define P(x) cout << #x << " = " << (x) << endl;

set < pair <int, int > > S;

bool dfs(int x, int y){
  if (! (1 <= x  && 1 <= y))
    return true;
  S.insert(make_pair(x, y));
  // P(x);
  // P(y);
  dfs(x - y, y);
  dfs(x, y - x);
  return true;
}

int dfs1(int x, int y){
  // P(x);
  // P(y);
  if (S.find(make_pair(x, y)) != S.end())
    return x + y;

  if (x < 1 || y < 1)
    return -1;

  int ret = -1;
  ret = max(ret, dfs1(x - y, y));
  ret = max(ret, dfs1(x, y - x));
  return ret;
}

int run(int a, int b, int c, int d){
  dfs(a, b);
  return dfs1(c, d);
}


int main(){
  P(run(1, 2, 2, 1));
  P(run(15, 4, 10, 7));
  P(run(1, 1, 10, 10));
  P(run(10944, 17928, 7704, 21888));
  P(run(1, 1, 1, 1));
  P(run(1000000, 4, 2,  1000000));
}
