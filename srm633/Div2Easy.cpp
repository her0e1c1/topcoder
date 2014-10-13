#include <topcoder.h>

vector<string>
run(int n){
  vector<string> s(n, string(n, '#'));

  // 準備
  for(int i = 1; i < n; i += 2){
    for(int j = 0; j < n; j++){
      s[i][j] = ' ';
    }
  }

  //偶数列
  for(int i = 0; i <= n / 2; i += 2){
    for(int j = 0; j < n / 2; j++){
      if (j < i && j % 2 == 1){
        s[i][j] = ' ';
        s[i][n - j - 1] = ' ';
        s[n - i - 1][j] = ' ';
        s[n - i - 1][n - j - 1] = ' ';
      }
    }
  }

  //奇数列
  for(int i = 1; i <= n / 2; i += 2){
    for(int j = 0; j < n / 2; j++){
      if(j < i && j % 2 == 0){
        s[i][j] = '#';
        s[i][n - j - 1] = '#';
        s[n - i - 1][j] = '#';
        s[n - i - 1][n - j - 1] = '#';

      }
    }
  }

  return s;
}

int main()
{
  PE(run(5));
  PE(run(9));
  PE(run(13));
  PE(run(17));
  return 0;
}
