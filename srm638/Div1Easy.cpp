#include <topcoder.h>

string run(vector<string> XY, vector<string> YZ, vector<string>ZX)
{

  int n = XY.size();
  int d[6][3] = {
    {0, 0, 1},
    {0, 0, -1},
    {0, 1, 0},
    {0, -1, 0},
    {1, 0, 0},
    {-1, 0, 0},
  };
  bool visited[10][10][10] = {false};

  function <bool(int, int, int)> check = [&] (int x, int y, int z){
    if (0 <= x < n && 0 <= y < n && 0 <= z < n &&
        XY[x][y] == 'Y' && YZ[y][z] == 'Y' && ZX[z][x] == 'Y')
      return true;
    else
      return false;
  };

  // ベクトルの初期
  vector<vector<vector<bool>>> compornents(10, vector<vector<bool>>(10, vector<bool>(10, false)));
  vector<vector<vector<bool>>> f(10, vector<vector<bool>>(10, vector<bool>(10, false)));

  function <void(int, int, int)> dfs = [&] (int x, int y, int z){
    if (!visited[x][y][z]){
      visited[x][y][z] = true;
      compornents[x][y][z] = true;
      for(int i = 0; i < 6; i++){
          int nx = x + d[i][0];
          int ny = y + d[i][1];
          int nz = z + d[i][2];
          if (check(nx, ny, nz))
            dfs(nx, ny, nz);
      }
    }
  };

  function <bool()> ok = [&] (){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        bool x = false, y = false, z = false;
        for(int k = 0; k < n; k++){
          if (compornents[i][j][k])
            x = true;
          if (compornents[k][i][j])
            y = true;
          if (compornents[j][k][i])
            z = true;
        }
        if (x != (XY[i][j] == 'Y') ||
            y != (YZ[i][j] == 'Y') ||
            z != (ZX[i][j] == 'Y')){
          return false;
        }
      }
    }
    return true;
  };

  if (ok())
    return "OK";

  for(int x = 0; x < n; x++){
    for(int y = 0; y < n; y++){
      for(int z = 0; z < n; z++){
        if (check(x, y, z)){
          compornents = f;
          dfs(x,y,z);
          if(ok())
            return "POSSIBLE";
        }
      }
    }
  }
  return "IMPOSSIBLE";
}

int main()
{
  P(run({"YN","NN"},
        {"YN","NN"},
        {"YN","NN"}));

  P(run({"YN","NY"},
        {"YN","NY"},
        {"YN","NY"}));

  P(run({"YYY","YNY","YYY"},
        {"YYY","YNY","YYY"},
        {"YYY","YNY","YYY"}));

  P(run({"YYY","YNY","YYY"},
        {"NYY","YNY","YYY"},
        {"YYY","YNY","YYN"}));

  P(run({"N"},
        {"N"},
        {"N"}));

}
