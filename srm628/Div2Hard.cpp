#include <iostream>
#include <vector>

using namespace std;

#define P(x) cout << #x << " = " << (x) << endl;
#define PE(x)                                   \
  for (int i = 0 ; i < (x).size(); i++){        \
    cout << #x << "[" << i << "]" << " = " << (x)[i] << endl;   \
  }
#define SIZE(x) (sizeof(x) / sizeof(x[0]))
#define V(x, ...)                               \
  int __ ## x [] = {__VA_ARGS__};               \
  vector<int> x(__ ## x, __ ## x + SIZE(__ ## x));

#define PA(x)                                   \
  cout << #x << " = ";                          \
  for (int i = 0; i < SIZE(x); i++){            \
    cout << x[i] << ", ";                       \
  }                                             \
  cout << endl;                                 \

vector<int> F;
int rev[51], inloop[51], visit[51];
int L;

// 自分よりも小さく、かつ、根を記憶
// rev[i] == i ならば cycleの根元と考える
int dfs1(int u){
  int v = F[u];
  if (v < u)
    return dfs1(v);
  else
    return u;
}

// 枝を回っていき、自分に戻るかどうか調べる
// 親は１つしかないので常に次どこへ移動するか決まっている
int dfs2(int u){
  visit[u] = true;
  int v = F[u];
  if (visit[v])
    return v;
  else
    return dfs2(v);
}

int dfs3(int u){
  for (int i = 0; i < L; i++){
    int v = F[u];
    if (!inloop[v]){
    }
  }
}

long run(vector<int> f){
  F = f;
  L = f.size();
  memset(inloop, 0, sizeof(inloop));
  for (int i = 0; i < L; i++) {
    memset(visit, 0, sizeof(visit));
    rev[i] = dfs1(i);
    if (dfs2(i) == i){
      inloop[i] = 1;
    }
  }
  // PA(rev)
  // PA(inloop)
  long ret = 0;
  for (int i = 0; i < L; i++) if(i == rev[i]){
      memset(visit, 0, sizeof(inloop));
      for (int k = 0; i < L; k++){}
      if (rev[i] );
  }
  return 0;
}

int main(){
  V(v0, 1,0,0,0)
  P(run(v0))
}
