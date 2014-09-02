#include <topcoder.h>

/*
 * f(x) = |xs1 - t1| + |xs2 - t2| + ... |xsn - tn|
 * min f(x) を求める
 * x = s/t = Volume/Weight が候補となる(証明は別途考えておく)
 */

double
run(VI containerVolume, VI desiredWeight)
{
  int size = containerVolume.size();
  VD candidates(size);
  REP(i, size)
    candidates[i] = (double)desiredWeight[i] / (double)containerVolume[i];

  double ret = INF;
  REP(i, size){
    double sum = 0;
    REP(k, size){
      sum += abs(candidates[i] * (double)containerVolume[k] - (double)desiredWeight[k]);
    }
    ret = min(sum, ret);
  }
  return ret;
}

int
main()
{
  V(int, v00, 5);
  V(int, v01, 1000);
  P(run(v00, v01));

  V(int, v10, 10,10);
  V(int, v11, 1000,2000);
  P(run(v10, v11));

  V(int, v20, 10,20,40);
  V(int, v21, 4000,2000,1000);
  P(run(v20, v21));

  V(int, v30, 1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121);
  V(int, v31, 3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223);
  P(run(v30, v31));

  V(int, v40, 30621, 30620, 2);
  V(int, v41, 1, 1 ,1000000);
  P(run(v40, v41));
  return 0;
}
