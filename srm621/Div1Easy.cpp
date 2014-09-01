#include <topcoder.h>

/*
 * 確率が連続値ではあるが、その場合は区間の長さををその起こる確率とすればよい。
 * 点は、微小区間/起こりうる区間 なので、0としてよい
 *
 * A B C D E のそれぞれの区間がどちらに属するか判定するわかりやすい判断方法は、
 * 先にプロットして、境界線を明確にした後、それぞれの区間がどっちに含まれるか考えるのが簡単
 */

VI X, Y, R;
int N;
double Z;

// ピタゴラス
double dest(int i){
  return sqrt(X[i] * X[i] + Y[i] * Y[i]);
}

double run(VI x, VI y, VI r, int z){
  N = x.size();
  X = x; Y = y; R = r, Z = z;

  vector<double> plots;
  plots.push_back(0);
  plots.push_back(z);

  FOR(i, 0, N){
    double d = dest(i);
    double begin = d - R[i];
    double end = d + R[i];
    if (begin > 0)
      plots.push_back(begin);
    plots.push_back(end);
  }

  // 全ての境界線を求めたら、順番にソートする
  sort(ALL(plots));
  // PE(plots);

  double length = 0;
  FOR(i, 0, plots.size() - 1){
    double begin = plots[i];
    double end = plots[i + 1];

    bool in_a_city = false;
    FOR(k, 0, N){
      int d = dest(k);
      double b = d - R[k];
      double e = d + R[k];
      if (b <= begin && end <= e){
        // P(d);
        in_a_city = true;
      }
    }
    if (! in_a_city){
      if (begin <= z && z <= end){
        // P(begin)
        // P(end)
        length += z - begin;
      }
      else if (end <= z){
        // P(begin)
        // P(end)
        length += end - begin;
      }
    }
  }
  return length / (double)z;
}

int main(){
  V(int, v00, 0);
  V(int, v01, 0);
  V(int, v02, 5);
  P(run(v00, v01, v02, 10));

  // V(int, v10, 10);
  // V(int, v11, 10);
  // V(int, v12, 10);
  // // P(run(v10, v11, v12, 10));

  // V(int, v20, 10);
  // V(int, v21, 10);
  V(int, v22, 10);
  P(run(v20, v21, v22, 10));

  V(int, v30, 11, -11, 0, 0);
  V(int, v31, 0, 0, 11, -11);
  V(int, v32, 10, 10, 10, 10);
  P(run(v30, v31, v32, 31));

  V(int, v40, 100);
  V(int, v41, 100);
  V(int, v42, 1);
  P(run(v40, v41, v42, 10));

  // 32bitだから多分桁あふれ
  V(int, v50, 1000000000);
  V(int, v51, 1000000000);
  V(int, v52, 1000000000);
  P(run(v50, v51, v52, 1000000000));

  V(int, v60, 20, -20, 0, 0);
  V(int, v61, 0, 0, 20, -20);
  V(int, v62, 50, 50, 50, 50);
  P(run(v60, v61, v62, 100));

  // 32bitだから多分、誤差が拡大?
  V(int, v70, 0, -60, -62, -60, 63, -97);
  V(int, v71, -72, 67, 61, -8, -32, 89);
  V(int, v72, 6, 7, 8, 7, 5, 6);
  P(run(v70, v71, v72, 918));
}
