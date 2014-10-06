#include <topcoder.h>

VI V;
int K, N, ANS;

VI E[1001];
VI VIS;
LL LIMIT = 10000;
VI BIT;


int
read(int index)
{
  int sum = 0;
  while(index > 0){
    sum += BIT[index];
    index -= index & -index;
  }
  return sum;
}

void
update(int index, int value)
{
  while(index < LIMIT){
    BIT[index] += value;
    index += index & -index;
  }
}

/*
 * :at: 現在のNode
 * :togo: カウンタ
 * :invs: 現在の最小invs
 */

// 始点がN通り
// それぞれについて、???
// よってdfsはN^2の計算量

// 1recごとに1回inversionを求める
// 反転数が最も小さいものを返す
// Kよりも多く数える必要ない(最小値を求めるから)

void
rec(int at, int togo, int invs){
  --togo;
  // P(at);
  // P(togo);
  // P(invs);
  int newInvs = read(V[at] - 1);

  if (togo == 0){
    ANS = min(invs + newInvs, ANS);
    return;
  }

  update(V[at], 1);
  VIS[at] = true;
  for (int i = 0; i < E[at].size(); i++){
     int v = E[at][i];
     if (! VIS[v]){
       rec(v, togo, newInvs + invs);
     }
  }
  update(V[at], -1);
  VIS[at] = false;
}

int run(VI a, VI b, VI v, int k){
  ANS = LIMIT;
  N = a.size();
  V = v;
  K = k;
  BIT.resize(LIMIT);
  VIS.resize(N);
  REP(i, 1001) E[i].clear();
  REP(i, N){
    int u_ = a[i];
    int v_ = b[i];
    E[u_].push_back(v_);
    E[v_].push_back(u_);
  }
  for(int i = 0; i < N; i++){
  // for(int i = 0; i < 1; i++){
    REP(k, LIMIT) BIT[k] = 0;
    REP(k, N) VIS[k] = false;
    update(V[i], 1);
    VIS[i] = true;
    rec(i,  K, 0);
  }
  return ANS == LIMIT ? -1 : ANS ;
}


int main(){
  P(run(
        {0,1,2},
        {1,2,0},
        {40,50,60},
        3));

  P(run(
        {0,1,2,3},
        {1,2,3,0},
        {60,40,50,30},
        3));

  P(run(
        {0,1,2,3,0},
        {1,2,3,0,4},
        {10,10,10,5,5},
        5));

  P(run(
  {0,1,2,3,0,2},
  {1,2,3,0,4,5},
  {10,2,5,3,7,1},
  6));

  P(run(
        {5,7,7,5,5,7,6,4},
  {2,0,2,0,1,4,7,3},
  {15,10,5,30,22,10,5,2},
  6
       ));
  return 0;
}
