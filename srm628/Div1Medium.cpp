#include <topcoder.h>

/*
  1. 使用するXの個数を数え上げる
  2. 大きい方から順番に足したものが最大となる

  stack構造なので幅優先探索(bfs)を使用する
  bfs() depth++ で同じ構造と模倣できる
*/

VI CONDUCTORS;
string CIRCUIT;
int DEPTH;

int bfs(){
  char c = CIRCUIT[DEPTH];
  DEPTH++;
  if (c == 'X')
    return 1;
  else if (c == 'A')
    return bfs() + bfs();
  else if (c == 'B')
    return max(bfs(), bfs());
  else
    return 0;
}

int run(string circuit, VI conductors){
  CIRCUIT = circuit; CONDUCTORS = conductors;
  DEPTH = 0;
  sort(conductors.rbegin(), conductors.rend());
  int n = bfs();
  return accumulate(conductors.begin(), conductors.begin() + n, 0);
}

int main(){
  V(int, v0, 8, 2, 3);
  P(run("BXBXX", v0));

  V(int, v1,  1, 1, 2, 8, 10);
  P(run("AAXXAXAXX", v1));

  V(int ,v2, 8, 2, 3);
  P(run("AXBXX", v2));

  V(int ,v3 ,17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30);
  P(run("BAAXBXXBXAXXBBAXXBXXAAXXX", v3));

}
