#include <topcoder.h>

/*
 * N/2 -1, N/2 にW or Bを塗る場合のみ考える
 * 0, 1, 2の三パターンしか答えがない
 * 2回、逆側の色で濡れば、確実に連続しなくなる
 */

bool
check(vector<string> s)
{
  int N = s.size();
  REP(y, N){
   int counter = 1;
   char color = s[0][y];
   FOR(x, 1, N){
     if (s[x][y] == color){
       counter++;
     } else {
       counter = 1;
     }
     if (counter > N / 2)
       return false;
    }
  }
  return true;
}

int
run(vector<string> s)
{
  int N = s.size();
  if (check(s))
    return 0;

  int A[] = {-1, 0, -1, 0};
  char C[] = {'W', 'W', 'B', 'B'};

  FOR(i, 0, 4){
    vector<string> c = s;
    int col = N / 2 + A[i];
    REP(j, N) c[col][j] = C[i];
    // P(i);
    // P(col);
    // P(C[i]);
    // P(c[0][0]);
    // P(c[0][1]);
    // P(c[1][0]);
    // P(c[1][1]);
    if (check(c))
      return 1;
  }

  return 2;
}

int
main()
{

  P(run(
  {"WB",
  "BB"}
  ));

  P(run(
        {"WB",
         "WW"}
        ));

  P(run(
        {"WB",
         "WB"}
        ));

  P(run(
        {"WBBW",
         "WBWB",
         "WWBB",
         "BWWW"}
        ));

  P(run(
        {"WBBWBB",
         "BBWBBW",
         "WWBWBW",
         "BWWBBB",
         "WBWBBW",
         "WWWBWB"}
        ));

  return 0;
}
