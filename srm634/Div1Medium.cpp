#include <topcoder.h>

/*
 * 頂点を辺をつなぐことの対応関係が一番大切
 *
 * 線分を１つのノードとみなす
 * i => i + N は、コストの小さい方をきることになる
 * 中途半端に流れることに特に意味はない。最大流量のときに、その線分（segment)を除外する
 * 線分が交差するときを考えるが、
 * 一つの線分（例えば赤）に対して、交差する別の色の線分（青）をかんがえる
 * 赤を除外するなら、そのノードに対して最大流量が流れる
 * そうでないなら、交差する青のノードが全てmaxとなる(コストの小さい方のどちらか)
 *
 */

#define x first
#define y second
typedef pair<int,int> PII;

int N, M, L, S, T;
int CAP[1000][1000];
int FLOW[1000][1000];
int flow[1000][1000];
//int IINF = 1 << 14;
#define IINF 1000000000

int edmonds(int s, int t) {
int n = 2+2*L*L;
int b,e,q[n],p[n],d,FLOW=0;
FOR(i,0,n) FOR(j,0,n) flow[i][j]=0;
for(;;) {
FOR(i,0,n) p[i]=-1;
for(q[b=e=0]=s;b<=e;b++)
  FOR(v,0,n) 
    if (flow[q[b]][v] < CAP[q[b]][v] && p[v]<0)
      p[q[++e]=v] = q[b];
if (p[t]<0) break;
d = CAP[p[t]][t] - flow[p[t]][t];
for(int i=t;i!=s;i=p[i]) d=min(d,CAP[p[i]][i]-flow[p[i]][i]);
 for(int i=t;i!=s;i=p[i]) {
   flow[p[i]][i] += d;
   flow[i][p[i]] -= d;
 }
 FLOW += d;
 }
 return FLOW;
}

// int edmonds(int s, int t){
//   int b, e, q[N], p[N], f=0;
//   FOR(i, 0, N) FOR(j, 0, N) FLOW[i][j] = 0;
//   for(;;){
//     FOR(i, 0, N) p[i] = -1;
//     for(q[b=e=0]=s; b<=e; b++){
//       FOR(v, 0, N){
//         if (CAP[q[b]][v] > FLOW[q[b]][v] && p[v] < 0){
//           p[v] = q[b];
//           q[++e] = v;
//           // p[q[++e]=v] = q[b];
//         }
//       }
//     }
//     if (p[t] == -1)
//       break;
//     int d = CAP[p[t]][t] - FLOW[p[t]][t];
//     for(int i=t; i!=s; i=p[i])
//       d = min(d, CAP[p[i]][i] - FLOW[p[i]][i]);
//     for(int i=t; i!=s; i=p[i]){
//       FLOW[i][p[i]] -= d;
//       FLOW[p[i]][i] += d;
//     }
//     f += d;
//   }
//   return f;
// }

// 二つの線分が平行でない場合は交わる
// bool intersect(PII a, PII b, PII p, PII q){
//   int D1 = (a.x - b.x) * (p.y - q.y);
//   int D2 = (a.y - b.y) * (p.x - q.x);
//   return D1 != D2;
// }

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

PII operator-(PII a, PII b){
  return PII(a.x - b.x, a.y - b.y);
}

int run(vector<int> x, vector<int> y, vector<int> redScore, vector<int> blueScore){
  L = x.size();
  M = redScore.size();
  N = 2+2*M;
  S = 2*M;
  T = S + 1;

  int n = 2 + 2*L*L;
  S = n-2;
  T = n-1;

  int ret = 0;
  vector<PII> P;
  FOR(i, 0, L) P.push_back(make_pair(x[i], y[i]));
  //FOR(i, 0, N) CAP[i%L][i/L] = 0;
//FOR(i, 0, M) ret += redScore[i] + blueScore[i];


int m = x.size();
FOR(i,0,m*m){
ret += redScore[i] + blueScore[i];
CAP[S][i] = redScore[i];
CAP[i+m*m][T] = blueScore[i];
}

FOR(a,0,m)
FOR(b,0,m)
FOR(p,0,m)
FOR(q,0,m)
if(intersect(P[a], P[b], P[p], P[q]))
  CAP[a*m+b][m*m+p*m+q] = IINF;
return (ret-edmonds(S, T))/2;
  // FOR(i, 0, M){
  //   int n0 = i%L;
  //   int n1 = i/L;
  //   CAP[S][i] = redScore[i];
  //   CAP[i + M][T] = blueScore[i];
  //   CAP[i][i + M] = IINF;
  //   FOR(j, 0, M){
  //     int n2 = j%L;
  //     int n3 = j/L;
  //     if(intersect(PII(x[n0], y[n0]), PII(x[n1], y[n1]), 
  //                  PII(x[n2], y[n2]), PII(x[n3], y[n3]))){
  //       CAP[i][j+M] = IINF;
  //     }
  //   }
  // }
  // return (ret - edmonds(S, T)) / 2;
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
