#include <topcoder.h>


int edmonds(int s, int t, int n, vector<vector<int>> cap) {
  int b,e,q[n],p[n],d,mf=0;
  vector<vector<int>> flow(n, vector<int>(n, 0));

  for(;;) {
    FOR(i,0,n) p[i]=-1;
    for(q[b=e=0]=s;b<=e;b++)
      FOR(v,0,n) 
        if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
          p[q[++e]=v] = q[b];
    if (p[t]<0) break;
    d = cap[p[t]][t] - flow[p[t]][t];
    for(int i=t;i!=s;i=p[i])
      d=min(d,cap[p[i]][i]-flow[p[i]][i]);
    for(int i=t;i!=s;i=p[i]) {
      flow[p[i]][i] += d;
      flow[i][p[i]] -= d;
    }
    mf += d;
  }
  return mf;
}

int run(VI a, VI b, VI c, VI d, VI score){
  int ans = 0;
  int n, s, t;
  n = score.size();
  s = n;
  t = n + 1;
  int an = n + 2;

  // FOR(root, 0, 1){
  FOR(root, 0, n){
    // vector<vector<int>> cap(1000, vector<int>(1000, 0));
    vector<vector<int>> cap(an, vector<int>(an, 0));

    function<void(VI, VI)> doDFS = [&] (const VI  &u, const VI  &v){
      function <void(int, int)> dfs = [&] (int i, int parent){
        for(int j = 0; j < a.size(); j++){
          int k = -1;
          if (u[j] == i){
            k = v[j];
          } else if (v[j] == i){
            k = u[j];
          }
          if (k != -1 && parent != k){
            cap[i][k] = INF;
            dfs(k, i);
          }
        }
      };
      dfs(root, -1);
    };
    doDFS(a, b);
    doDFS(c, d);

    FOR(i,0,n){
      if (score[i] >= 0)
        cap[i][t] = score[i];
      else
        cap[s][i] = -score[i];
    }
    int sum = 0;
    FOR(i, 0, n) if(score[i] > 0) sum += score[i];

    // P(an);
    // P(cap[0][0]);
    // P(cap[0][1]);
    // P(cap[0][2]);
    // P(cap[0][3]);
    // P(cap[0][4]);
    // P(cap[0][5]);

    // P(cap[1][0]);
    // P(cap[1][1]);
    // P(cap[1][2]);
    // P(cap[1][3]);
    // P(cap[1][4]);
    // P(cap[1][5]);

    // P(cap[2][0]);
    // P(cap[2][1]);
    // P(cap[2][2]);
    // P(cap[2][3]);
    // P(cap[2][4]);
    // P(cap[2][5]);

    // P(cap[3][0]);
    // P(cap[3][1]);
    // P(cap[3][2]);
    // P(cap[3][3]);
    // P(cap[3][4]);
    // P(cap[3][5]);

    // P(cap[4][0]);
    // P(cap[4][1]);
    // P(cap[4][2]);
    // P(cap[4][3]);
    // P(cap[4][4]);
    // P(cap[4][5]);

    // P(cap[5][0]);
    // P(cap[5][1]);
    // P(cap[5][2]);
    // P(cap[5][3]);
    // P(cap[5][4]);
    // P(cap[5][5]);

    ans = max(ans,  sum - edmonds(s, t, an, cap));
  }
  return ans;
}

int main()
{

  P(run({0,0,1},
        {1,3,2},
        {0,0,3},
        {1,3,2},
        {1000,24,100,-200}));


  P(run({0,0,1},
        {1,3,2},
        {0,0,3},
        {1,3,2},
        {1000,24,100,200}));

  P(run({0,0,1},
        {1,3,2},
        {0,0,3},
        {1,3,2},
        {-1000,-24,-100,-200}));

  P(run({0,0,1},
        {1,3,2},
        {0,0,3},
        {1,3,2},
        {-1000,24,100,200}));

  P(run({0,0,1,1,2,2},
        {1,2,3,4,5,6},
        {0,0,1,1,2,2},
        {1,2,3,4,5,6},
        {-3,2,2,-1,2,2,-1}));

  P(run({0,0,1,1,2,2},
        {1,2,3,4,5,6},
        {0,0,0,0,0,0},
        {1,2,3,4,5,6},
        {-3,2,2,-1,2,2,-1}));
 
  return 0;
}
