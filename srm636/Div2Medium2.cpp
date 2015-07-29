#include <topcoder.h>
#include <algorithm>
// another answer with next_permutation
int N;

int main()
{
  P(run(5, {4, 0, 0, 2, 0}));
  P(run(4, {0, 0, 0, 0}));
  P(run(2, {1, 3, 2}));
  P(run(2, {1, 2, 0, 5, 0, 0}));

  return 0;
}
