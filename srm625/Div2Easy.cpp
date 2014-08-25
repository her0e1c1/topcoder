#include <topcoder.h>


// y = x[2] + (x[0] * x[1])
// x[i] != 0
// x[i] != 1
VI run(int y){
  VI ret(3, 0);
  for (int i = -1000; i <= 1000; i++)
    for (int j = -1000; j <= 1000; j++){
      if (i == 0 || i == 1 ||
          j == 0 || j == 1)
        continue;
      if ((y - j) % i == 0){
        if (ret[i] == 0 || ret[i] == 1)
          continue;
        ret[2] = j;
        ret[1] = (y - j) / i;
        ret[0] = i;
        return ret;
      }
  }
  return ret;
}

int main(){
  PE(run(6));
  PE(run(11));
  PE(run(0));
  PE(run(500));
  PE(run(2));
  PE(run(5));
}
