#include <topcoder.h>


int run(vector<int> size, int maxSizeSum){
  int n = size.size();
  vector<int> index(n);
  for(int i = 0; i < n; i++){
    index[i] = i;
  }

  int ans = 0;
  do {
    bool flag = true;
    for(int i = 0; i < n; i++){
      for(int k = i + 1; k < n; k++){
        int a = index[i];
        int b = index[k];
        if (a > b && size[a] + size[b] > maxSizeSum){
          flag = false;
          break;
        }
      }
    }
    if (flag)
      ans++;
  } while(next_permutation(index.begin(), index.end()));

  return ans;
}

int main(){
  P(run({1, 2, 3},
        3));

  P(run({1, 2, 3},
        1000));

  P(run({1, 2, 3},
        4));

  P(run({1,1,1,1,1,1},
        2));

  P(run({2,4,6,1,3,5},
        8));

  P(run({1000},
        1000));

}
