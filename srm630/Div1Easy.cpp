#include <topcoder.h>

/*
 * washall floyd を利用して、それぞれのnode間の距離を求めておく
 * 同じ距離の数が最大になるものを求める

 * ネットワークの形状がtreeなので、サイクルしないため、
 * 正三角形のような形状は無視してよい

 * 中心からの距離が等長なもののうち、同じ経路を含まないことが条件
 */

// 桁溢れしないように1<<31みたいのは使えない
#define LIMIT 10000

int
run(int n, VI a, VI b, VI len)
{
  if (n == 1)
    return 1;

  int size = a.size();
  
  vector<vector<int> > E(n);
  vector<vector<int> > dest(n, vector<int> (n, LIMIT));
  vector<vector<int> > weight(n, vector<int>(n, LIMIT));

  // edgeを使いやすい構造に変換
  REP(i, size){
    int u = a[i] - 1;
    int v = b[i] - 1;
    int w = len[i];
    // 枝もまとめておく(事前の数が不明なのでpush_back)
    E[u].push_back(v);
    E[v].push_back(u);  // 同じものがない場合？

    weight[u][v] = w;
    // 逆向きも同じ距離
    weight[v][u] = w;
  }

  REP(i, n)
    REP(j, n){
    if (i == j){
      dest[i][i] = 0;
    } else {
      dest[i][j] = weight[i][j];
    }
  }

  FOR(k, 0, n){
    REP(i, n)
      REP(j, n){
      int d = dest[i][k] + dest[k][j];
      if (dest[i][j] > d)
        dest[i][j] = d;
      }
  }

  // 各ハブを調査し、同一経路でない等長の数を調べる
  // x => c => y と x => yが同じものを調べる
  int ret = 0;
  for (int x = 0; x < n; x++){
    map<int, int>M;
    // 初期化
    REP(i, n) M.insert(make_pair(dest[x][i], 0));

    for (int i = 0; i < E[x].size(); i++){
      set<int> S;
      // cは、xに直接つながっているもの
      int c = E[x][i];
      for (int y = 0; y < n; y++){
        // cを通過する同じ経路のもの
        if (dest[x][c] + dest[c][y] == dest[x][y]){
          S.insert(dest[x][y]);  // 存在すれば１つだけカウント
        }
      }
      EACH(it, S) M[*it]++;
    }
    EACH(it, M){
      ret = max(ret, it->second);
    }
  }

  return ret;
}

int
main()
{
  V(int, v00, 1,1,1);
  V(int, v01, 2,3,4);
  V(int, v02, 1,1,1);
  P(run(4, v00, v01, v02));

  // 3を中心としたときに、1と5の一方のみを含むようにしたい
  V(int, v10, 1,2,3,2,3);
  V(int, v11, 2,3,4,5,6);
  V(int, v12, 2,1,3,2,3);
  P(run(6, v10, v11, v12));

  V(int, v20, 1,1,1,1,1,1,1,1,1);
  V(int, v21, 2,3,4,5,6,7,8,9,10);
  V(int, v22, 1000,1000,1000,1000,1000,1000,1000,1000,1000);
  P(run(10, v20, v21, v22));

  V(int, v30, );
  V(int, v31, );
  V(int, v32, );
  P(run(1, v30, v31, v32));

  return 0;
}
