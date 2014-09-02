#include <topcoder.h>

/*
 * boardの四つの角をholeから出す条件
 * 1. 少なくとも一方が、holeの1辺を超える(同じは不可)
 * 候補は、1を満たしたboardのうち、もう一方の辺が大きいものから順に使う
 * complexity = 2 * boardH.size()
 */

int
check(int boundary, int length, VI boardH, VI boardW)
{
  int size = boardH.size();
  vector<pair<int, int> > candidates;

  // must be outside of boundary
  REP(i, size){
    int h = boardH[i];
    int w = boardW[i];
    int small = min(h, w);
    int big = max(h, w);
    // use first element as covering boundary
    if (boundary < small){
      candidates.push_back(MP(small, big));
    }
    else if (boundary < big){
      candidates.push_back(MP(big, small));
    }
  }

  sort(RALL(candidates));

  int sum = 0;
  REP(i, candidates.size()){
    sum += candidates[i].second;
    if (sum >= length){
      return i + 1;
    }
  }
  return INF;
}

int
run(int holeH, int holeW, VI boardH, VI boardW)
{
  int ret1 = check(holeH, holeW, boardH, boardW);
  int ret2 = check(holeW, holeH, boardH, boardW);
  int ret = min(ret1, ret2);
  return ret == INF ? -1 : ret;
}

int
main()
{
  V(int, v00,8,8,8);
  V(int, v01,2,3,4);
  P(run(5, 5, v00, v01));

  V(int, v10,6,6,6,6);
  V(int, v11,6,6,6,6);
  P(run(10, 10, v10, v11));

  V(int, v20,5);
  V(int, v21,5);
  P(run(5, 5, v20, v21));

  V(int, v30,6);
  V(int, v31,4);
  P(run(3, 5, v30, v31));

  V(int, v40,12345,12343,12323,12424,1515,6666,6789,1424,11111,25);
  V(int, v41,1442,2448,42,1818,3535,3333,3456,7890,1,52);
  P(run(10000, 5000, v40, v41));

  return 0;
}
