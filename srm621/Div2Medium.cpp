#include <topcoder.h>

int N;
vector<int> S;
set<int> MEMO;

void dfs(int i, int sum){
  if (i == N)
    MEMO.insert(sum);
  else{
    dfs(i + 1, sum + S[i]);
    dfs(i + 1, sum);
  }
}

int run(vector<int> s){
  MEMO.clear();
  S = s;
  N = s.size();
  dfs(0, 0);

  for (int i = 1; i < INF; i++){
    if (MEMO.count(i) == 0)
      return i;
  }
  return -1;
}

int main(){
  V(int, v0, 5, 1, 2);
  P(run(v0));

  V(int, v1, 2, 1, 4);
  P(run(v1));

  V(int, v2, 2, 1, 2, 7);
  P(run(v2));

  V(int ,v3, 94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1);
  P(run(v3));

  V(int, v4, 883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13);
  P(run(v4));
}
