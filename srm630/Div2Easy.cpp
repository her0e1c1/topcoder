#include <topcoder.h>

/*
 * そもそもiteratorは、コンテナの要素をさすので、pointerではないみたい
 * せっかくなのでpointerを使って解く
 * advanceは、その第一引数を破壊的に変更するので注意
 * (it + 1) がエラーな理由?
 * it++ とは意味が違うみたい
 * it += 1もできない
 * it = 1はあり得ない
 * ポインタを初期化できない？
 * list<char>::IT last_but_one = NULL;
 * pointerをboolとして扱うには?
 */

bool
delete_element(list<char>& s){
  list<char>::IT last_but_one = s.end();
  advance(last_but_one, -1);
  for(list<char>::IT it = s.begin(); it !=last_but_one; it++){
    list<char>::IT i1 = it;
    list<char>::IT i2 = it;
    advance(i2, 1);
    if (*i1 == *i2){
      // eraseしても順番は変わっても、ポインタは変わらないみたい
      s.erase(i1);
      s.erase(i2);
      return true;
    }
  }
  return false;
}

string
run(string S)
{
  list<char> s(ALL(S));
  while (delete_element(s))
    ;
  if (s.empty())
    return "POSSIBLE";
  else
    return "IMPOSSIBLE";
}

int
main()
{
  P(run("aabccb"));
  P(run("aabccbb"));
  P(run("abcddcba"));
  P(run("abab"));
  P(run("aaaaaaaaaa"));
  P(run("aababbabbaba"));
  P(run("zzxzxxzxxzzx"));

  return 0;
}
