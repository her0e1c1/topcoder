#include <topcoder.h>

/*
 * current = 0010101
 * currentの次にする場合は、0を1に変更する
 
 * 001011? がはじめの方の候補?
 * 1?????? が終わりの方の候補?
 * 1111111 は必ずspecialになることを利用する
 */

// // bool isSpecial(string s)
// {
//   // returns true if the string is special
//   int n = s.size();
//   for (int i = 1; i < n; i++) { //O(n^2)
//     if (s.substr(0,i) >= s.substr(i)) { //O(n)
//       return false;
//     }
//   }
//   return true;
// }

bool isSpecial(string s)
{
  int n = s.size();
  for(int i = 1; i < n; i++){
    string s1(s, 0, i);  // 前方
    string s2(s, i, n);  // 後方
    // P(s1);
    // P(s2);
    // P(" ");
    if (s1 >= s2)
      return false;
    // all j st s1 < s2 lexicologically
    // for(int j = 0; j < s1.size() && j < s2.size(); j++){
    //   if (s1[j] > s2[j]){  // 確実にfalse
    //     P(s1);
    //     P(s2);
    //     P(j);
    //     return false;
    //   }
      // else if (s1[j] == s2[j])
      // 同じも不可
    // }
  }
  return true;
}

string
run(string current)
{
  int n = current.size();
  for(int i = n - 1; i >= 0; i--){
    // currentが0で開始されるもので、indexの小さい順から探索
    // 辞書順なので、後方（右側）から変更させていけばいい
    if (current[i] != '0')
      continue;

    // 一つ以上先のもののうち、1埋めするものを作成
    string c = current;
    for(int j = n - 1; j >=i; j--){
      c[j] = '1';
    }
    if (isSpecial(c)){
      for(int k = i + 1; k < n; k++){
        c[k] = '0';
        if (! isSpecial(c)){
          c[k] = '1';
        }
      }
      return c;
    }
  }
  return "";
}


int main()
{
  // P(isSpecial("0101"));
  // P(isSpecial("00101"));
  // P(isSpecial("01101111011111111"));
  // P(_isSpecial("01101111011111111"));

  P(run("01"));
  P(run("00101"));
  P(run("0010111"));
  P(run("000010001001011"));
  P(run("01101111011110111"));
  
  return 0;
}
