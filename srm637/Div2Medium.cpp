#include <topcoder.h>

vector<int> MEMO[2][2];
VS B;
int h,w;

int dfs(int above, int x, int y)
{
  if (y == w-1)
    return MEMO[0][x][y] = MEMO[1][x][y] = 1;

  if (MEMO[above][x][y] != -1)
    return MEMO[above][x][y];

  // 右へ移動
  int ret = 10000;
  if (B[x][y + 1] == '.')
    ret = min(ret, dfs(x, x, y + 1) + 1);
  // 下へ移動
  if (above == 0 && x == 0 && B[1][y] == '.')
    ret = min(ret, dfs(0, 1, y) + 1);
  // 上へ移動
  if (above == 1 && x == 1 && B[0][y] == '.')
    ret = min(ret, dfs(1, 0, y) + 1);

  return MEMO[above][x][y] = ret;
}

// find the shortest path
int run(VS board){
  B = board;
  h = 2;
  w = board[0].size();
  int ans = 0;
  FOR(i, 0, 2)
    FOR(j, 0, 2){
      MEMO[i][j].clear();
      MEMO[i][j].resize(w);
      FOR(k, 0, w)
        MEMO[i][j][k] = -1;
  }
  int black = 0;
  FOR(i,0,h)
    FOR(j,0,w)
    black += board[i][j] == '#';

  int S = w*h - black;
  int path = 10000;
  if (B[0][0] == '.')
    path = min(path, dfs(0, 0, 0));
  if (B[1][0] == '.')
    path = min(path, dfs(1,1,0));

  // P(h);
  // P(w);
  // P(black);
  // P(S);
  // P(path);

  // REP(i, 2){
  //   REP(j, w){
  //     int p = MEMO[0][i][j];
  //     if (p > 100)
  //       p = 99;
  //     printf("%3d", p);
  //   }
  //   printf("\n");
  // }

  // REP(i, 2){
  //   REP(j, w){
  //     int p = MEMO[1][i][j];
  //     if (p > 100)
  //       p = 99;
  //     printf("%3d", p);
  //   }
  //   printf("\n");
  // }

  return S - path;
}

int main()
{
  P(run({"#....", "...#."}));
  P(run({"#" ,"."}));
  P(run({"." ,"."}));
  P(run({"....#.##.....#..........." ,"..#......#.......#..#...."}));
  P(run({"................#...............", ".....................#.........."}));  // 29
  P(run({"###............................##.................", "....######.....###############....################"}));  // 5 
  return 0;
}
