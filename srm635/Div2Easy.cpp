#include <topcoder.h>

string run(string s, string t)
{
  int cur = 0;
  for(int i = 0; i < s.size(); i++){
    if (s[i] == t[cur])
      cur++;
    if (cur == t.size())
      return "Yep, it's wood.";
  }
  return "Nope";
}

int main()
{
  P(run("absdefgh", "asdf"));
  P(run("xoxox", "ooxxoo"));
  P(run("oxoxoxox", "xxx"));
  P(run("qwerty", "qwerty"));
  P(run("string","longstring"));

  return 0;
}
