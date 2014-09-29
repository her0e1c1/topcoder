#include <topcoder.h>

// (0, 0) から (x, y) に含まれる charを格納
map<char ,vector<vector<int> > > TOTAL;
string TYPES = "AP.";
int N;

// (x0, y0), (x1, y1)に含まれるtypeの数だけ返す
int rectangle(char type, int x0, int y0, int x1, int y1){
  vector<vector<int> >  t = TOTAL[type];
  return t[x1][y1] - t[x0][y1] - t[x1][y0] + t[x0][y0];
}

int run(VS board, int k){
  N = board.size();
  int ret = 0;

  // TOTALは、長方形(0, 0) から (x, y)に存在する各TYPEの個数
  // ただし便宜上1ずつずれている。
  REP(t, TYPES.size()){
    char type = TYPES[t];
    vector<vector<int> > ttl(N + 1, VI (N + 1));
    REP(i, N) ttl[i][0] = 0;
    REP(i, N) ttl[0][1] = 0;
    FOR(x, 1, N + 1)
      FOR(y, 1, N + 1){
        int has = (board[x - 1][y - 1] == type);
        ttl[x][y] = has + ttl[x][y - 1] + ttl[x - 1][y] - ttl[x - 1][y - 1];
    }
    TOTAL[type] = ttl;
  }

  // それぞれの数
  int A = TOTAL['A'][N][N];
  int P = TOTAL['P'][N][N];
  int D = TOTAL['.'][N][N];

  // P(A);
  // P(P);
  // P(D);

  FOR(x0, 0, N){
    FOR(y0, 0, N){
      FOR(x1, x0 + 1, N + 1){
        FOR(y1, y0 + 1, N + 1){
          // 使用する長方形を決定
          int w = x1 - x0;
          int h = y1 - y0;
          int a = rectangle('A', x0, y0, x1, y1);
          int p = rectangle('P', x0, y0, x1, y1);
          int d = rectangle('.', x0, y0, x1, y1);

          // if (w * h == 2 && d == 1){
          //   P(" ");
          //   P(a);
          //   P(p);
          //   P(d);
          // }
          // A で埋める場合 (.はAと交換、pは外側にある.と交換。
          // もし内側にしかない場合は、先に.とAを交換)
          // 枠内が全てAの場合もOK(つまりp == 0)
          if ((D > 0 || p == 0) && w * h <= A && d + 2 * p <= k)
            ret = max(ret, w * h);

          // P で埋める場合
          if ((D > 0 || a == 0) && w * h <= P && d + 2 * a <= k)
            ret = max(ret, w * h);

          // . で埋める場合
          // 内側にAがあれば外側の.と交換(Pも同じ)
          if (w * h <= D && a + p <= k)
            ret = max(ret, w * h);
        }
      }
    }
  }
  return ret;
}


int main() {
  
  P(run({"AA", "AA"}, 0));
  P(run({"AP", ".A"}, 0));
  P(run({"AP", ".A"}, 1));
  P(run({".PP", "PPA", "PAP"}, 3));
  P(run({"A.P.PAAPPA",
      "PPP..P.PPP",
      "AAP.A.PAPA",
      "P.PA.AAA.A",
      "...PA.P.PA",
      "P..A.A.P..",
      "PAAP..A.A.",
      "PAAPPA.APA",
      ".P.AP.P.AA",
          "..APAPAA.."}, 10));
}


