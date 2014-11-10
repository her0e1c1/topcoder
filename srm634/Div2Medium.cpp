#include <topcoder.h>

int run(int N, VI s)
{
  int ans = N;
  int n = s.size();
  int K = n;

  vector<int> items(N, 0);
  sort(RALL(s));

  // 0を優先的に加えていく
  FOR(i,0,n){
    // increment from 0 to val
    int val = s[i];
    FOR(j,0, val){
      items[j]++;
    }
  }
  
  // K - 1以下の余剰を求める
  int reminder = 0;
  int people = 0;
  FOR(i,0,N){
    if (items[i] <= K - 1)
      reminder += (K - 1) - items[i];
    else
      people++;  // あふれた場合
  }

  // P(people);
  // P(reminder);

  if (people == 0)
    return 0;

  int max_value = people;
  // ひとつずつK-1以下になるように調節する
  for(int i = people - 1; i >= 0; i--){
    int d = items[i] - (K - 1);
    if (reminder >= d){
      reminder -= d;
      max_value--;
    }
  }
  return max_value;
}


int main()
{
  P(run(5,
        {3, 3}));

  P(run(100,
        {97}));

  P(run(10,
        {9, 9, 9, 9, 9}));

  P(run(7,
        {1, 2, 3}));

  P(run(5,
        {3, 3, 3}));


  return 0;
}
