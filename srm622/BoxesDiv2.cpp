#include <iostream>
#include <vector>

using namespace std;

int pow(int n){
  int i = 1;
  while(true){
    if (i >= n)
      return i;
    i *= 2;
  }
}

class BoxesDiv2 {
public:
  int findSize(vector<int> candyCounts){
    while (true){
      sort(candyCounts.rbegin(), candyCounts.rend());
      int n = candyCounts.size(); 
      if (n >= 2){
        int a = pow(candyCounts[n - 1]);
        int b = pow(candyCounts[n - 2]);
        int c = 2 * max(a, b);
        candyCounts[n - 2] = c;
        candyCounts.resize(n - 1);
      } else {
        break;
      }
    }
    return candyCounts[0];
  }
};

#define SIZE(x) (sizeof(x) / sizeof(x[0]))
#define A(x, ...)                               \
  int __ ## x [] = {__VA_ARGS__};               \
  vector<int> x(__ ## x, __ ## x + SIZE(__ ## x))
int main(){
  V(1, 2, 3);
  A(a, 1, 2, 3);
  A(b, 1, 2, 3);
  cout << a[0];
}
