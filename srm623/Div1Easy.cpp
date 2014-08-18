#include <topcoder.h>

VS BOARD;
int K, N, TX, TY, BX, BY;
int NA, NP, ND;
int W, H;

/*
  1. 長方形の形が不明
  2. はじめから形を決めておく
     NC2 * NC2 通り <= 20C2 ** 20C2
     なので、たかだか36100通り
  3. 1 <= 求める面積 <= N * N
  4. 左上(TX, TY) 右下(BX, BY) を頂点とする長方形を列挙
    :subject: 0 <= TX <= BX <= N-1and 0 <= TY <= BY <= N-1
  5. '.' が内側にあるときは、外側の'A'を移動
     'P' が内側にあるときは、外側の'.'へ'P'を移動させ、'A'を内側移動
  6. 少なくとも1つは'.'が必要
*/

// すべて'A'で埋めることができたらtrue
bool dfs(){
  // P(TX);
  // P(TY);
  // P(BX);
  // P(BY);
  // P(W);
  // P(H);
 int counter = 0;
  if (W * H > NA)
    return false;
  for (int x = TX; x <= BX; x++)
    for (int y = TY; y <= BY; y++){
      char c = BOARD[x][y];
      if (c == 'A')
        ;
      else if (c == 'P'){
        if (ND > 0)
          counter += 2;
        else
          return false;
      }
      else if (c == '.')
        counter += 1; 
    }
  // P(counter);
  return counter <= K;
  
}

int run(VS board, int k){
  BOARD = board; K = k;
  N = board.size();
  NA = 0; NP = 0; ND = 0;
  int ret = 0;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++){
      if (board[i][j] == 'A') NA++;
      else if (board[i][j] == 'P') NP++;
      else if (board[i][j] == '.') ND++;
    }

  // [(0, 0), (0, 0)] ... [(0, 0), (0, N - 1)]
  for (int tx = 0; tx < N; tx++)
    for (int ty = 0; ty < N; ty++)
      for (int bx = tx; bx < N; bx++)
        for (int by = ty; by < N; by++){
          TX = tx; TY = ty; 
          BX = bx; BY = by; 
          W = bx - tx + 1;
          H = by - ty + 1;
          if (dfs()){
            ret = max(W * H, ret);
          }
        }
  return ret;
}

int main() {
  
  V(string, v0, "AP", ".A");
  P(run(v0, 0));

  V(string, v1, "AP", ".A");
  P(run(v1, 1));

  V(string, v2, "PPP", "APA", "A.P");
  P(run(v2, 2));

  V(string, v3, "AAA", "PPP", "AAA");
  P(run(v3, 10));

  V(string, v4, ".");
  P(run(v4, 1000));

  V(string, v5, "PPAAPA..AP", "PPA.APAP..", "..P.AA.PPP", "P.P..APAA.", "P.P..P.APA", "PPA..AP.AA", "APP..AAPAA", "P.P.AP...P", ".P.A.PAPPA", "..PAPAP..P");
  P(run(v5, 10));
}
