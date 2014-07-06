#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FixedDiceGameDiv2 {
public:
  double getExpectation(int a, int b){
    int count = 0;
    int rv = 0;
    for (int i = 1; i < b + 1; i++){
      for (int j = i + 1; j < a + 1; j++){
        rv += j;
        count++;
      }
    }
    return rv / (double)count;
  }
};
  
int main(int argc, char* argv[]){
  FixedDiceGameDiv2 f;
  int a[4][2] = {
    {2, 2},
    {4, 2},
    {3, 3},
    {11, 13},
  };
  for(int i = 0 ; i < 4; i++){
    printf("%lf\n", f.getExpectation(a[i][0], a[i][1]));
  }
}
