#include <topcoder.h>

int run(VI s, VI t)
{
  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    if (s[i] > t[i])
      ans++;
  }
  return ans;
}

int main()
{
  P(run({1,3}, {4,2}));
  P(run({1,3,5,7,9}, {2,4,6,8,10}));
  P(run({2}, {1}));
  P(run({3,5,9,16,14,20,15,17,13,2}, {6,18,1,8,7,10,11,19,12,4}));
  return 0;
}
