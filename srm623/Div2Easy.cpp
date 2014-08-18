#include <topcoder.h>

int N;
VI X, Y;
VI INDEX;

bool dfs(int i, int c_x, int c_y){
  if (i == N)
    return true;

  int index = INDEX[i];
  int t_x = X[index];
  int t_y = Y[index];

  bool ret = false;
  if (c_x == t_x && c_y == t_y){
    ret = dfs(i + 1, c_x, c_y);
  } else if (c_x == t_x && c_y < t_y){
    ret = dfs(i, c_x, c_y + 1);
  } else if (c_x < t_x && c_y < t_y){
    ret = dfs(i, c_x + 1, c_y + 1);
  } else if (c_x > t_x && c_y < t_y){
    ret = dfs(i, c_x - 1, c_y + 1);
  }
  return ret;
}

bool cmp(int a, int b){
  return Y[a] < Y[b];
}

string run(VI x, VI y){
  X = x; Y = y;
  N = x.size();

  REP(i, N) INDEX.PB(i);
  sort(ALL(INDEX), cmp);

  return dfs(0, 0, 0) ? "OK" : "NO";
}

int main(){
  V(int, v00, -1, 1, 0);
  V(int, v01, 1, 3, 4);
  P(run(v00, v01));

  V(int, v10, -1, 1, 0);
  V(int, v11, 1, 2, 4);
  P(run(v10, v11));

  V(int, v20, 0, -1, 1);
  V(int, v21, 9, 1, 3);
  P(run(v20, v21));

  V(int, v30, 70,-108,52,-70,84,-29,66,-33);
  V(int, v31, 141,299,402,280,28,363,427,232);
  P(run(v30, v31));

  V(int, v40, -175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66);
  V(int, v41, 320,107,379,72,126,445,318,255,445,62,52,184,247,245,185           );
  P(run(v40, v41));

  V(int, v50, 0,0,0,0 );
  V(int, v51, 0,0,0,0 );
  P(run(v50, v51));

}
