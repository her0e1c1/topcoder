#include <topcoder.h>

/*
 * 1, -1のどちらを優先的に求めたほうがよいか？
 * 条件
 * 一方はより大きく
 * 一方はイコールでもよい
 *
 * 
 */

int
chech(int hmax, int hmin, int bmax, int bmin)
{
  if (hmax >= bmax && hmin >= bmin)
    return -1;
  else
    return 1;
}

int
run(int holeH, int holeW, int boardH, int boardW)
{
  int hmax = max(holeH, holeW);
  int hmin = min(holeH, holeW);

  int bmax = max(boardH, boardW);
  int bmin = min(boardH, boardW);

  return chech(hmax, hmin, bmax, bmin);
}

int
main()
{
  P(run(1,1,1,1));
  P(run(3, 5, 4, 6));
  P(run(10, 20, 25, 15));
  P(run(3, 10, 3, 12));

  return 0;
}
