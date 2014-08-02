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
#define P(x) cout << #x << " = " << (x) << endl;
int main(){
  BoxesDiv2 b;
  A(v1, 8,8);
  P(b.findSize(v1));
  A(v2, 5,6);
  P(b.findSize(v2));
  A(v3, 1,7);
  P(b.findSize(v3));
  A(v4, 1,1,13,1,1);
  P(b.findSize(v4));
  A(v5, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32);
  P(b.findSize(v5));
}
