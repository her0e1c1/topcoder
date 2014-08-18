#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define P(x) cout << #x << " = " << (x) << endl;

int GX, GY;

bool dfs(int x, int y){
  if (x == GX && y == GY)
    return true;
  else if (! (x <= GX && y <= GY))
    return false;

  bool ret = false;
  ret = max(ret, dfs(x + y, y));
  ret = max(ret, dfs(x, x + y));
  return ret;
}

string run(int a, int b, int c, int d){
  GX = c, GY = d;
  return dfs(a, b) ? "Good" : "Bad";
}


int main(){
  P(run(1, 2, 3, 5));
  P(run(2, 2, 2, 999));
  P(run(2, 2, 2, 1000));
  P(run(47, 58, 384, 221));
  P(run(1000, 1000, 1000, 1000));
}
