#include <topcoder.h>

string run(string s, int k)
{
  int size = s.size();
  for (char c = 'a'; c <= 'z'; c++){
    string copy = s;
    int counter = 0;
    for(int i = 0; i < size; i++){
      if (copy[i] != c){
        copy[i] = c;
        counter++;
      }
      if (counter == k){
        string ans(size, c);
        if (ans == copy)
          return ans;
      }
    }
  }
  return "";
}

int main()
{
  P(run("hello", 3));
  P(run("abc", 3));
  P(run("wwwwwwwwwwwwwwwwww", 0));
  P(run("ababba", 3));
  P(run("zoztxtoxytyt", 10));
  P(run("jlmnmiunaxzywed", 13));

  return 0;
}
