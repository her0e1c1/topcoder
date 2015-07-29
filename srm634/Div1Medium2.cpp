#include<vector>
#include<iostream>
using namespace std;
 
#define FWD(i,a,b) for(int i=(a); i<(b); i++)
#define x first
#define y second
typedef pair<int,int> PII;
typedef long long LL;
#define INF 1000000000
 
 
PII operator-(PII a, PII b){
  return PII(a.x-b.x, a.y-b.y);
}
 
int side(PII a, PII b, PII c){
  LL d = (LL)(b.x-a.x)*(c.y-a.y)-(LL)(c.x-a.x)*(b.y-a.y);
  if(d < 0) return -1;
  if(d > 0) return 1;
  return 0;
}
 
bool intersect(PII a, PII b, PII p, PII q){
  if(a == p || a == q || b == p || b == q) return 1;
  return side(a,b,p)!=side(a,b,q) && side(p,q,a)!=side(p,q,b);
}
 
int n, cap[1000][1000];
int flow[1000][1000];
 
int edmonds(int s, int t) {
  int b,e,q[n],p[n],d,FLOW=0;
  FWD(i,0,n) FWD(j,0,n) flow[i][j]=0;
  for(;;) {
    FWD(i,0,n) p[i]=-1;
    for(q[b=e=0]=s;b<=e;b++)
      FWD(v,0,n) 
        if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
          p[q[++e]=v] = q[b];
    if (p[t]<0) break;
    d = cap[p[t]][t] - flow[p[t]][t];
    for(int i=t;i!=s;i=p[i]) d=min(d,cap[p[i]][i]-flow[p[i]][i]);
    for(int i=t;i!=s;i=p[i]) {
      flow[p[i]][i] += d;
      flow[i][p[i]] -= d;
    }
    FLOW += d;
  }
  return FLOW;
}
 
#define P(x) cout << x << endl;

  int run(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore)
  {
    int m = x.size();
    vector<PII> P;
    FWD(i,0,m) P.push_back(PII(x[i], y[i]));
    n = 2+2*m*m;
    int s = n-2;
    int t = n-1;
    int res = 0;
    FWD(i,0,m*m){
      res += redScore[i] + blueScore[i];
      cap[s][i] = redScore[i];
      cap[i+m*m][t] = blueScore[i];
    }
    FWD(a,0,m)
      FWD(b,0,m)
      FWD(p,0,m)
      FWD(q,0,m)
      if(intersect(P[a], P[b], P[p], P[q]))
        cap[a*m+b][m*m+p*m+q] = INF;
    return (res-edmonds(s, t))/2;
  }
  
int main()
{
  P(run({0,1,0,-1},
        {1,0,-1,0},
        {0, 1, 2, 3,
         1, 0, 6, 4,
         2, 6, 0, 5,
         3, 4, 5, 0},
        {0, 2, 3, 7,
         2, 0, 4, 6,
         3, 4, 0, 5,
            7, 6, 5, 0}));

P(run({0, 1},
{1, 0},
{0, 101, 101, 0},
{0, 100, 100, 0}));

P(run({-3, -1, -1,  1,  1,  3},
{ 0, -2,  2, -2,  2,  0},
{0, 2, 1, 2, 1, 2,
   2, 0, 2, 1, 2, 1,
   1, 2, 0, 2, 1, 2,
   2, 1, 2, 0, 2, 1,
   1, 2, 1, 2, 0, 2,
   2, 1, 2, 1, 2, 0},
{0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0,
   0, 0, 0, 21, 0, 0,
   0, 0, 21, 0, 0, 0,
   0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0}));


P(run({-100, 100, 0, -10, 10, 0},
{0, 0, 100, 10, 10, 1},
{ 0, 96, 96, 25, 25, 25,
    96,  0, 96, 25, 25, 25,
    96, 96,  0, 25, 25, 25,
    25, 25, 25,  0, 10, 10,
    25, 25, 25, 10,  0, 10,
    25, 25, 25, 10, 10,  0},
{ 0, 30, 30, 20, 20, 20,
    30,  0, 30, 20, 20, 20,
    30, 30,  0, 20, 20, 20,
    20, 20, 20,  0, 86, 86,
    20, 20, 20, 86,  0, 86,
    20, 20, 20, 86, 86,  0}));

P(run({1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
{1, 4, 9, 16, 25, 36, 49, 64, 81, 100},
{0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
   15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
   2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
   3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
   4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
   5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
   6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
   7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
   8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
   9, 8, 7, 6, 5, 4, 3, 2, 15, 0},
{0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
   0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
   2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
   3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
   4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
   5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
   6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
   7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
   8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
   9, 8, 7, 6, 5, 4, 3, 2, 0, 0}));

  return 0;
}
