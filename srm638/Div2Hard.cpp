#include <topcoder.h>

int run(vector<int> A, vector<int> B, vector<int> len){
  int inf = 1000000;
  int n = A.size();
  vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
  vector<set<int>> E(n + 1);
  for(int i = 0; i < n; i++){
    int u = A[i];
    int v = B[i];
    int l = len[i];
    w[u][v] = l;
    w[v][u] = l;
    E[u].insert(v);
    E[v].insert(u);
  }

  vector<int> leaves;
  for(int i = 0; i < E.size(); i++){
    if(E[i].size() == 1)
      leaves.push_back(i);
  }
  int t = leaves.size();

  set<float> ans;
  for(int mask = 1; mask < (1 << t); mask++){
    // P("start");
    P(mask);
    vector<int> Q;
    vector<int> dest(n + 1, INF);
    vector<int> parent(n + 1, -1);
    for(int i = 0; i < t; i++){
      if (mask & (1 << i)){
        Q.push_back(leaves[i]);
        P(leaves[i]);
        dest[leaves[i]] = 0;
      }
    }
    if (Q.size() == 0){
      P("next");
      continue;
    }

    float mx = 0;
    while(Q.size() > 0){
      int s = 0;
      for(int i = 1; i < Q.size(); i++){
        if (dest[Q[s]] > dest[Q[i]])
          s = i;
      }
      int x = Q[s];
      // P(x);
      // P(dest[x]);
      Q[s] = Q[Q.size() - 1];
      Q.pop_back();
      mx = max<float>(dest[x], mx);
      // P(mx);
      for(int n: E[x]){
        // P(dest[n]);
        // P(w[x][n]);
        // P(dest[x]);
        if (dest[n] > w[x][n] + dest[x]){
          // P(n);
          dest[n] = w[x][n] + dest[x];
          Q.push_back(n);
          parent[n] = x;
        }
      }
    }
    // n*nのデバッグプリントを作成する

    for(int i = 0; i < n; i++){
      int x = A[i], y = B[i], l = len[i];
      if (parent[x] != y && parent[y] != x && l >= abs(x - y)){
        float c = max(x, y) + (l - abs(x - y)) / 2.0;
        P(c);
        P(mx);
        mx = max<float>(mx, c);
        P(mx);
      }
    }
    ans.insert(mx);
  }
  EACH(it, ans)
    P(*it);
  return ans.size();
}

int main(){
  // P(run({0,1},
  //       {1,2},
  //       {10,1}));
 
  // P(run({0,0,0},
  //       {1,2,3},
  //       {1,1,1}));

  P(run({0,0,0},
        {1,2,3},
        {1,2,3}));

  // P(run({0,1,1,2,3,3,2,4},
  //       {1,2,3,4,5,6,7,8},
  //       {5,3,2,4,6,8,7,1}));

  // miss
  // P(run({0,0,0,0},
  //       {1,2,3,4},
  //       {123,456,789,1000}));

  // P(run({0},
  //       {1},
  //       {1000}));


}
