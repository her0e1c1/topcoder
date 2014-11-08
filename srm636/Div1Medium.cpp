#include <topcoder.h>

/*
 * n nodes, n edgesなので、必ずcycleができる
 * 2点間でサイクルはできるが、3点間では不可能(A=>B=>C=>Aとなるような距離は存在しない)
 * 重複を1つとみなせば、1つある場合、n-1 edges で1 tree
 * 2つなら、 n-2 edges で 2trees
 * xなら、 x edges => x trees (x components)
 * A<=>Bとなれば1、そうでなければ0と期待値とする
 * raditを区別しないと、nCr通り考えられる
 * 2点間を選び、それがサイクルする場合の数を数える
 * 残りn-2のスペースにrabitをおける。rabitはr-2匹。
 * rabitをおけないスペースの数を数える(b個あるとする)
 * (n - 2 - b)C(r - 2) 通りが求める場合の数になる。
 * ただし、n - 2 - b < r - 2は常に0とする
 */

int m,n,dot;

double run(vector<string> board, int r){
  m = board.size();
  n = board[0].size();
  dot = 0;
  double ans = 0;
  FOR(i,0,m)
    FOR(j,0,n)
    dot += board[i][j] == '.';

  vector<vector<double>> C(m*n, vector<double>(m*n, 0));
  for(int i = 0; i < n*m; i++){
    C[i][0] = 1;
    for(int j = 1; j <= i; j++){
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  vector<vector<int>> dist(m*n, vector<int>(m*n, 0));
  FOR(i, 0, m*n)
    FOR(j, i+1, m*n){
    int x0 = i / n;
    int y0 = i % n;
    int x1 = j / n;
    int y1 = j % n;
    dist[i][j] = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
    dist[j][i] = dist[i][j];
  }

  FOR(i,0,m*n-1)
    FOR(j,i+1,m*n){
      if (board[i/n][i%n] != '.')
        continue;
      if (board[j/n][j%n] != '.')
        continue;
    // iとjが重複する場合の数を数える
    int cnt = 0;
    FOR(k,0,m*n){
      if (board[k/n][k%n] != '.')
        continue;
      if (k == i || k == j)
        continue;
      double d = dist[i][j];
      if (!(d < dist[i][k] || (d == dist[i][k] && j < k)))
        continue;
      if (!(d < dist[j][k] || (d == dist[j][k] && i < k)))
        continue;
      cnt++;
    }
    ans += C[cnt][r-2];
  }
  return ans / C[dot][r];
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
