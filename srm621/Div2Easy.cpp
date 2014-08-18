#include <topcoder.h>

vector<string> S;
int N;

bool dfs1(int i, int cl){
  if (i == N)
    return true;
  int il = S[i].size();
  if (il >= cl)
    return dfs1(i + 1, il);
  else
    return false;
}

bool dfs2(){
  vector<string> T = S;
  sort(T.begin(), T.end());
  return S == T;
}

string run(vector<string> stringList){
  N = stringList.size();
  S = stringList;
  bool r1 = dfs1(0, 0);
  bool r2 = dfs2();
  if (r1 && r2)
      return "both";
  else if (r2)
    return "lexicographically";
  else if (r1)
      return "lengths";
  else
    return "none";
}

int main(){
  V(v0, "a", "aa", "bbb");
  P(run(v0));
  V(v1, "c", "bb", "aaa");
  P(run(v1));
  V(v2, "etdfgfh", "aio");
  P(run(v2));
  V(v3, "aaa", "z");
  P(run(v3));
  V(v4, "z");
  P(run(v4));
  V(v5, "abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder");
  P(run(v5));
}

