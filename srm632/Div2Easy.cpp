#include <topcoder.h>

vector<bool> VISIT;
VI D;
int N;
int SIZE;

void
dfs(int depth, int current)
{
  if (depth == N)
    return;
  if (current < D[depth] && ! VISIT[depth]){
    VISIT[depth] = true;
    dfs(depth + 1, D[depth]);
  } else {
    dfs(depth + 1, current);
  }
}

int
run(int n, VI d)
{
  N = n;
  SIZE = d.size();
  D = d;
  VISIT.resize(SIZE);
  REP(i, SIZE) VISIT[i] = false;

  int counter = 0;
  REP(i, N) {
    counter++;
    dfs(0, 0);
    if (all_of(ALL(VISIT), [] (bool i) { return i;}))
      break;
  }
  return counter;
}

int
main()
{
  P(run(3,
        {1,2,3}));

  P(run(24,
        {6,6}));

  P(run(3,
        {3,2,1}));

  P(run(50,
        {1,3,5,7,9,2,4,6,8,10}));

  return 0;
}
