#include <topcoder.h>

int R, T, VRAT, VCAT;

double run(int r, int t, int vrat, int vcat){
  R = r; T = t; VRAT = vrat;  VCAT = vcat;
  // ratが速い場合は追いつくことができない
  if (vrat >= vcat)
    return -1;

  // 最大でも円周の半分まで
  double dest = min<double>(vrat * t, PI * r);
  return dest / (double)(vcat - vrat);
}

int main(){
  P(run(10, 1, 1, 1));
  P(run(10, 1, 1, 2));
  P(run(10, 1, 2, 1));
  P(run(1000, 1000, 1, 1000));
  P(run(1, 1000, 1, 2));
  return 0;
}
