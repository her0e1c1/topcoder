#include <iostream>
#include <vector>

using namespace std;

#define P(x) cout << #x << " = " << (x) << endl;
#define PE(x)                                   \
  for (int i = 0 ; i < (x).size(); i++){        \
    cout << #x << "[" << i << "]" << " = " << (x)[i] << endl;   \
  }
#define SIZE(x) (sizeof(x) / sizeof(x[0]))
#define V(x, ...)                               \
  int __ ## x [] = {__VA_ARGS__};               \
  vector<int> x(__ ## x, __ ## x + SIZE(__ ## x))


class BuildingHeightsEasy{
public:
  int minimum(int M, vector<int> heights){
    sort(heights.begin(), heights.end());
    int sz = heights.size();
    int ret = 1000000;
    for (int i = 0; i <= sz - M; i++){
      int last = i + M - 1;
      int sum = 0;
      for (int k = i; k < last; k++){
        sum += heights[last] - heights[k];
      }
      ret = min(sum, ret);
    }
    return ret;
  }
};

int main(){
  BuildingHeightsEasy b;
  V(v0, 1, 2, 1, 4, 3);
  P(b.minimum(2, v0));

  V(v1, 1, 3, 5, 2, 1);
  P(b.minimum(3, v1));

  V(v2, 43, 19, 15);
  P(b.minimum(1, v2));

  V(v3, 19, 23, 9, 12);
  P(b.minimum(3, v3));

  V(v4, 25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4);
  P(b.minimum(12, v4));
}
