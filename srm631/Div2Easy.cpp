#include <topcoder.h>

vector<string> GRID;
int N;

int
low(int index, char color)
{
  function<int(int, int, int)> dfs = [&](int i, int current, int largest) {
    if (i == N)
      return largest;

    if (GRID[index][i] == color)
      return dfs(i + 1, current + 1, max(current + 1, largest));
    else
      return dfs(i + 1, 0, max(0, largest));
  };

  return dfs(0, 0, 0);
}

int
col(int index, char color)
{
  function<int(int, int, int)> dfs = [&](int i, int current, int largest) {
    if (i == N)
      return largest;

    if (GRID[i][index] == color)
      return dfs(i + 1, current + 1, max(current + 1, largest));
    else
      return dfs(i + 1, 0, max(0, largest));
  };

  return dfs(0, 0, 0);
}

int
run(vector<string> grid)
{
  GRID = grid;
  N = GRID.size();
  int largest = 0;
  for (int i = 0; i < N; i++){
    largest = max(low(i, 'W'), largest);
    largest = max(low(i, 'B'), largest);
    largest = max(col(i, 'W'), largest);
    largest = max(col(i, 'B'), largest);
  }

  return largest;
}

int
main()
{

  V(string, v1, "W");
  P(run(v1));

  V(string, v2, "WB", "BW");
  P(run(v2));

  V(string, v0, "BWW", "BBB", "BWB");
  P(run(v0));

  V(string, v3, "BWBW", "BBWB", "WWWB", "BWWW");
  P(run(v3));

  V(string, v4, "BWB", "BBW", "BWB");
  P(run(v4));

  V(string, v5, "BBWWBBWW", "BBWWBBWW", "WWBBWWBB", "WWBBWWBB", "BBWWBBWW", "BBWWBBWW", "WWBBWWBB", "WWBBWWBB");
  P(run(v5));

  return 0;
}
