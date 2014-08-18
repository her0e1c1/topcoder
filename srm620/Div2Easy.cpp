#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

#define P(x) cout << #x << " = " << (x) << endl;
#define PE(x)                                   \
  for (int i = 0 ; i < (x).size(); i++){        \
    cout << #x << "[" << i << "]" << " = " << (x)[i] << endl;   \
  }
#define SIZE(x) (sizeof(x) / sizeof(x[0]))
#define V(x, ...)                               \
  string __ ## x [] = {__VA_ARGS__};               \
  vector<string> x(__ ## x, __ ## x + SIZE(__ ## x))

bool cmp(pair<int, char> a, pair<int, char> b){

  if (a.second == b.second)
    return a.first < b.first;
  else
    return a.second < b.second;
}

vector<int> run(vector<string> score, int x){
  int N = score.size();
  vector< pair <int, char> > s(N);
  for (int i = 0; i < N; i++ ){
    s[i] = make_pair(i, score[i][x]);
  }
  sort(s.begin(), s.end(), cmp);
  vector<int> ret(N);
  for (int i = 0; i < N; i++){
    ret[i] = s[i].first;
  }
  return ret;
}

int main(){
  V(v0, "ACB", "BAC", "CBA");
  PE(run(v0, 1));

  V(v1, "A", "C", "B", "C", "A");
  PE(run(v1, 0));
  
  V(v2, "LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC");
  PE(run(v2, 2));

  V(v4, "XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY");
  PE(run(v4, 3));

  V(v5, "X");
  PE(run(v5, 0));
}
