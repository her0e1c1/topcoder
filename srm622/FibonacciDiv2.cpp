#include <iostream>
#include <vector>

using namespace std;

#define P(x) cout << #x << " = " << x << endl;

// Not use
int fib(int N){
  if (N == 0)
    return 0;
  else if (N == 1)
    return 1;
  else
    return fib(N - 1) + fib(N - 2);
}


class FibonacciDiv2 {
public:
  int find(int N){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);

    int i = 0;
    while(true){
      if (v[i] <= N && N <= v[i + 1])
        break;
      v.push_back(v[i] + v[i + 1]);
      i++;
    }
    
    return min(N - v[i], v[i + 1] - N);
  }
};

int main(){
  FibonacciDiv2 f;
  P(f.find(1));
  P(f.find(13));
  P(f.find(15));
  P(f.find(19));
  P(f.find(1000000));
}
