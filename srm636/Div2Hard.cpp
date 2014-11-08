#include <topcoder.h>

vector<vector<int>> rect;
int m,n;

int S(int x0, int y0, int x1, int y1){
  return rect[x1][y1] - rect[x1][y0] - rect[x0][y1] + rect[x0][y0];
}

bool check(int candidate){
  //P(candidate);
  FOR(x0, 1, m-2)
    FOR(x1, x0 + 1, m-1)
      FOR(x2, x1 + 1, m){
    int count = 0;
    int last = 0;
    FOR(y, 1, n+1){
      if (min(S(0 , last, x0, y),
          min(S(x0, last, x1, y),
          min(S(x1, last, x2, y), 
             (S(x2, last, m,  y))))) >= candidate){
        count++;
        // P(x0);
        // P(x1);
        // P(x2);
        // P(y);
        // P(count);
        last = y;
      }
    }
    if (count >= 4){
      // P(candidate);
      return true;
    }
  }
  return false;
}

int run(vector<string> cho){
  m = cho.size();
  n = cho[0].size();
  vector<vector<int>> r(m+1, vector<int>(n+1, 0));
  FOR(i, 1, m + 1)
    FOR(j, 1, n + 1){
    int x = cho[i-1][j-1] - '0';
    r[i][j] = x + r[i-1][j] + r[i][j-1] - r[i-1][j-1]; 
  }
  rect = r;
  // P(rect[1][1]);
  // P(rect[2][2]);
  // P(rect[2][3]);
  // P(rect[5][3]);

  // P(S(0,0,1,1));
  // P(S(0,0,1,2));
  // P(S(0,0,2,2));
  // P(S(1,1,2,2));
  // P(S(1,1,4,3));
  // P(S(3,0,5,3));

  int lo = 0, hi = m * n * 9 + 1;
  //P(check(3));
  while(lo + 1 < hi){
    int mid = lo + (hi - lo) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  //return hi;
  return lo;
}

int main()
{
  P(run({
      "95998",
      "21945",
      "23451",
      "99798",
      "74083"
      }));

  P(run({
    "12942",
      "23456",
      "99798",
      "98998",
      "67675"
      }));

  P(run({
    "129420",
      "234560",
      "997980",
      "989980",
"676760"
      }));

  P(run({"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"}));


  return 0;
}
