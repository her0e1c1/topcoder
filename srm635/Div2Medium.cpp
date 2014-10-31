#include <topcoder.h>

/*
 * d >= x + x^2
 * 0 >= x^2 + x - d
 * (x + 1/2)^2 - 1/4 - d <= 0
 * x + 1/2 = sqrt(d + 1/4)
 * x = sqrt(d + 1/4) - 1/2
 */

long run(long d)
{
  double x = sqrt(d + 1 / (double)4) - (1 / (double)2);
  int y = x;
  int ans = 0;
  // cout << y << endl;
  return y;
}

int main()
{
  P(run(1));
  P(run(2));
  P(run(5));
  P(run(6));
  P(run(7));
  P(run(1482));
  P(run(1000000000000000000));
  P(run(31958809614643170));

  return 0;
}
