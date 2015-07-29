#include <topcoder.h>

/*
 * count > 2 * time + 1 => 全て均等に移動できない（最低条件）
 * count > time + 1 => 全て一方に移動できない
 * positionでソートさせた方が多分よい
 * 左から考える(左端、右端はどこであるか？)
 * _ _ _ _ _ _ P _ _ _ _ P _ _ P _ P _ _ _ _ _ _ P _ _ _ _ _
 * 棒があって、それぞれ横に倒して、いい感じにずらす
 *
 * Pでソートする
 * 各P_iについて、最大[P_i - t, P_i + t] が移動できる幅となる
 * P_0 - t が左端となる
 * 左端から順に埋められるものがあれば、埋めていく(greedy)
 *  
 */


string
run(VI position, VI count, int time)
{
  vector<pair<int, int> > V;
  for(int i = 0; i < position.size(); i++){
    V.push_back(make_pair(position[i], count[i]));
  }

  // 位置でソート
  sort(ALL(V));
  
  for (int i = 0; i < V.size(); i++){
    
  }
  return "";
}

int
main()
{
  VI v00 {0};
  VI v01 {7};
  //P(run(v00, v01, 3));
  P(run({2, 0, 1}, {0, 1, 2}, 3));
  
  return 0;
}
