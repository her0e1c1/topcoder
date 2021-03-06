//ヘッダーは重複しない様に、1度しかインクルードしないようにします。
#ifndef TOPCODER
#define TOPCODER

//include
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//define
#define FOR(k,a,b) for(__typeof(a) k=(a); k < (b); k++)
#define REP(k,a) FOR(k,0,a)
#define ALL(c) (c).begin(), (c).end()  
#define RALL(a) (a).rbegin(), (a).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define EACH(i,c)    for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define CLR1(a) memset((a), -1 ,sizeof(a))
#define MAIN(void_func) int main(){void_func; return 0;}

//abbreviation
#define SZ size()
#define SIZE(x) (sizeof(x)/sizeof((x)[0]))
#define PB push_back 
#define MP make_pair 
#define VT value_type
#define IT iterator
#define INF (int)(1 << 30)
#define INFD (double)(1UL << 60)

#define P(x) cout << #x << " = " << (x) << endl;
#define PE(x)                                   \
  for (int i = 0 ; i < (x).size(); i++){        \
    cout << #x << "[" << i << "]" << " = " << (x)[i] << endl;   \
  }
#define PC(x)  \
  cout << #x << " = "; \
  for (int i = 0 ; i < (x).size(); i++){                          \
    cout << (x)[i] << ", ";   \
  }  cout << endl;

#define V(T, x, ...)                                 \
  T __ ## x [] = {__VA_ARGS__};               \
  vector<T> x(__ ## x, __ ## x + SIZE(__ ## x))

//typedef
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef map<string, int> MSI;
typedef map<int, string> MIS;
typedef map<int, int> MII;
typedef map<string, string> MSS;


const double EPS = 1e-10;
const double PI  = acos(-1.0);
//const long long MOD = 100.000.009
const long long MOD =   1000000009;

#endif  // TOPCODER
