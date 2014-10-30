#include <topcoder.h>

int run(VS chocolate){

  int ans = 0;
  int m = chocolate.size();
  int n = chocolate[0].size();

  vector<vector<int>> RECT(m+1, vector<int>(n+1, 0));
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
      int quo = chocolate[i-1][j-1] - '0';
      RECT[i][j] = quo + RECT[i][j-1] + RECT[i-1][j] - RECT[i-1][j-1];
    }

  // P(RECT[1][1]);
  // P(RECT[1][2]);
  // P(RECT[2][1]);
  // P(RECT[2][2]);

  function <int(int, int, int, int)> rect = [&] (int x0, int y0, int x1, int y1){
    return RECT[x1][y1] - RECT[x1][y0] - RECT[x0][y1] + RECT[x0][y0];
  };

  // P(rect(0,0,0,0));
  // P(rect(1,1,0,0));
  // P(rect(2,2,1,1));
  // P(rect(2,2,0,0));
  // P(rect(3,3,2,2));
  // P(rect(3,4,2,2));

  for (int x0 = 1; x0 < m - 1; x0++)
    for (int x1 = x0 + 1; x1 < m; x1++)
      for (int y0 = 1; y0 < n - 1; y0++)
        for (int y1 = y0 + 1; y1 < n; y1++){
          ans = max(ans,
                min(rect(x0,y0,0,0),
                min(rect(x0,y1,0,y0),
                min(rect(x0,n,0,y1),
                min(rect(x1,y0,x0,0),
                min(rect(x1,y1,x0,y0),
                min(rect(x1,n,x0,y1),
                min(rect(m,y0,x1,0),
                min(rect(m,y1,x1,y0), rect(m,n,x1,y1))))))))));
        }

  return ans;
}

int main()
{

  P(run({
        "9768",
        "6767",
        "5313"}));

  P(run({
    "36753562",
      "91270936",
      "06261879",
      "20237592",
      "28973612",
"93194784"
      }));

  P(run({
    "012",
      "345",
"678"
      }));

  return 0;
}
