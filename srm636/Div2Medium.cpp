#include <topcoder.h>

int N;
VI unused;

int inv(VI seq){

  int n = 0;
  for(int i = 0; i < N - 1; i++){
    // i < j
    for(int j = i + 1; j < N; j++){
      if (seq[i] < seq[j])
        n++;
    }
  }
  return n;

}

int run(int sortedness, VI seq) {
  int ans = 0;
  N = seq.size();
  unused.clear();
  FOR(i, 1, N+1){
    if (find(ALL(seq), i) == seq.end())
      unused.push_back(i);
  }

  // P(unused[0]);
  // P(unused[1]);
  // P(unused[2]);
  // P(unused[3]);
  // P(unused[4]);

  // P(inv({1,2,3}));
  // P(inv({2,3,1}));
  // P(inv({3,2,1}));

  VI vis(unused.size(), false);
  function <void(int)> dfs = [&] (int depth) {
    if (depth == N){
      // P(seq.size());
      // FOR(i,0,N)
      //   cout << seq[i] << ", ";
      // cout << endl;
      if (inv(seq) == sortedness)
        ans++;
      return;
    }

    if (seq[depth] != 0)
      return dfs(depth+1);

    FOR(i, 0, unused.size()){
      if (vis[i]) continue;
      // P(i);
      // P(depth);
      vis[i] = true;
      int u = unused[i];
      seq[depth] = u;
      dfs(depth+1);
      seq[depth] = 0;
      vis[i] = false;
    }
  };

  dfs(0);
  return ans;
}

int main()
{
  P(run(5, {4, 0, 0, 2, 0}));
  P(run(4, {0, 0, 0, 0}));
  P(run(2, {1, 3, 2}));
  P(run(2, {1, 2, 0, 5, 0, 0}));

  return 0;
}
