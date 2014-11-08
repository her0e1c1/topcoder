#include <topcoder.h>

double run(vector<string> board, int r)
{
  int h = board.size(), w = board[0].size();
  // find the empty cells, keep their indexes in the correct order.
  vector<int> x, y;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '.') {
        x.push_back(i);
        y.push_back(j);
      }
    }
  }
  int n = x.size();
  int dist[n][n]; //the square of the pair-wise distances
  // It is b
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      dist[i][j] = dx*dx + dy*dy;
    }
  }
  // Pascal's triangle to calculate the binomial coeficient.
  double C[n+1][n+1];
  memset(C, 0, sizeof(C));
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
  }
  double res = 0;
  // For each pair of cells (i,j):
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int b = 0;
      // Count bad cells (shouldn't be included if we want i<->j to be
      // a double edge.:
      for (int k = 0; k < n; k++) {
        if ( (k == i) || (k == j) ) {
          continue;
        }
        bool ok = true;
        if ( (dist[i][k] < dist[i][j]) || (dist[i][k] == dist[i][j] && k < j) ) {
          ok = false;
        }
        if ( (dist[j][k] < dist[j][i]) || (dist[j][k] == dist[j][i] && k < i) ) {
          ok = false;
        }
        if (! ok) {
          b++;
        }
      }
      res += C[n - 2  - b][r - 2] / C[n][r];
    }
  }
     
     
  return res;
}


int main()
{
  P(run({".#.#."}, 2));
  P(run({"..###.", ".###.#"}, 4));
  P(run({"..###.", ".###.#"}, 5));
  P(run({".....", "#...."}, 4));

  P(run({".#####.#####..#....#",
            "#......#....#.##..##",
            ".####..#####..#.##.#",
            ".....#.#...#..#....#",
          "#####..#....#.#....#"},
      19));

  return 0;
}
