#include <topcoder.h>

/*
 * 0は奇数
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
 * 0 1 0 2 0 1 0 3 0 1  0  2  0  1  0  4  0  1  0  2  0  1  0  3  0  1  0  2  0  1  0  5
 */

VI D;
int N;

VI
seq(int n)
{
  VI v;
  // 奇数
  int length = (1 << n) - 1;

  if (n == 0)
    return v;

  if (n == 1){
    v.push_back(0);
    return v;
  }

  v.resize(length);
  for(int i = 0; i < length / 2 ; i++){
    P(i);
    v[i] = 0;
    v[i + 1] = i + 1;
    v[length - i - 1] = i + 1;
    v[length - i] = 0;
  }
  

  return v;
}

bool
dfs(int start, int end, int current, int big, int should)
{
  // if (current == end){
  //   ;
  // }

  // int v = D[current];
  // if (v == 0)
  //   return dfs(start, end, current + 1, big, should);
  // if (v == should)
  //   return dfs(start, end, current + 1, , should - 1);
    
  return true;
}

int
run(VI d)
{
  D = d;
  N = d.size();
  int ret = 0;
  for(int i = 0; i < N ; i++){
    for(int j = i; j < N ; j++){
      if (i == j)
        ret++;
      for(int k = i; k <= j; k++){
        
      }
    }
  }
  return ret;
}

int
main()
{
  VI v = seq(3);
  PE(v);
  //P(run({0,1,0,2,0,1,0}));
  return 0;
}
