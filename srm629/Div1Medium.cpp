#include <topcoder.h>

vector<bool> VISIT;
vector<int> T1, N1, T2, N2;
int N;
int BIG = 1000000;

int
get_next(int index)
{
  REP(i, N) if (! VISIT[i]){
    if (T1[i] == T2[index])
      return i;
  }
  REP(i, N) if (! VISIT[i]){
    if (T2[i] == T2[index]){
      swap(T2[i], T1[i]);
      swap(N2[i], N1[i]);
      return i;
    }
  }

  return -1;
}

int
dfs(bool first, bool prev, int index)
{
  if (index == -1){
    if (first && prev)
      return BIG;
    else if (first)
      return 0;
    else if (prev)
      return 0;
    else
      return BIG;
  }

  VISIT[index] = true;
  int next = get_next(index);
  if (index == 2){
    P(next);
  }
  int ret = BIG;
  if (prev){
    ret = min(ret, dfs(first, true, next) + N1[index] + 1);
    ret = min(ret, dfs(first, false, next));
    // P(next);
    // P(dfs(first, false, next));
    // P(prev);
    // P(index);
    // P(next);
    // P(ret);
  } else {
    ret = min(ret, dfs(first, true, next) + max(N1[index], N2[index]) + 1);
    ret = min(ret, dfs(first, false, next) + N2[index] + 1);
    // if(index == 2){
    //   P(dfs(first, true, next));
    //   P(next);
    //   P(max(N1[index], N2[index]) + 1);
    //}
    // P(prev);
    // P(index);
    // P(next);
    // P(ret);
  }

  return ret;
}

int
run(VI t1, VI n1, VI t2, VI n2)
{
  T1 = t1; N1 = n1;
  T2 = t2; N2 = n2;
  N = t1.size();
  VISIT.resize(N);
  REP(i, N) VISIT[i] = false;

  int total = 0;
  REP(i, N) if (! VISIT[i]){
    VISIT[i] = true;
    vector<pair <int, vector<bool> > >m;
    int ret = BIG;
    int next = get_next(i);
    vector<bool> copy(ALL(VISIT));
    // ret = min(ret, dfs(false, false, next));
    // m.PB(make_pair(ret, VISIT));
    // VISIT = copy;
    ret = min(ret, dfs(false, true, next) + N1[i] + 1);
    m.PB(make_pair(ret, VISIT));
    VISIT = copy;
    // ret = min(ret, dfs(true, false, next) + N2[i] + 1);
    // m.PB(make_pair(ret, VISIT));
    // VISIT = copy;
    // ret = min(ret, dfs(true, true, next) + max(N1[i], N2[i]) + 1);
    // m.PB(make_pair(ret, VISIT));
    sort(ALL(m));
    VISIT = m[0].second;
    total += m[0].first;
  }

  return total;
}

int
main()
{
  // P(run(
  // {0,0},
  // {1,1},
  // {1,1},
  // {1,1}
  // ));

  // P(run(
  // {0,0},
  // {2,5},
  // {1,1},
  // {2,5}
  // ));

  // P(run(
  // {0,0,2,3},
  // {1,1,2,2},
  // {1,1,3,2},
  // {1,1,2,2}
  // ));

  P(run(
  {0,1,2,3},
  {5,5,10,13},
  {1,2,3,0},
  {8,8,10,15}
  ));

  // P(run(
  // {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13},
  // {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530},
  // {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16},
  // {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394}
  // ));

  // 0 右 1 なし 2 両方 => -1 となる (3 ?)
  return 0;
}
