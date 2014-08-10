#include <iostream>

#define P(x) cout << #x << " = " << (x) << endl;

using namespace std;

int R1, R2, C1, C2;

bool is_move(int type){
  for (int i = -8; i < 8; i++){
    int r = R1 + i;
    int c = C1 + (i * type);
    // == となっているので、必ずボード内にあることが保証されている
    if (0 <= r && r <=8 && 0 <= c && c <= 8)
      if (r == R2 && c == C2)
        return true;
  }
  return false;
}

int run(int r1, int c1, int r2, int c2){
  R1 = r1;
  C1 = c1;
  R2 = r2;
  C2 = c2;

  if (((r1 + c1) % 2) != ((r2 + c2) % 2))
    return -1;

  if (r1 == r2 && c1 == c2)
    return 0;
  else if (is_move(1) || is_move(-1))
    return 1;
  else
    return 2;
}

int main(){
  P(run(4, 6, 7, 3));
  P(run(2, 5, 2, 5));
  P(run(1, 3, 5, 5));
  P(run(4, 6, 7, 4));
}
