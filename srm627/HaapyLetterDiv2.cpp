#include <iostream>
#include <topcoder.h>

using namespace std;

char run(string letters){
  int buff[51] = {0};
  for (int i = 0; i < letters.size(); i++){
    int s = letters[i] - 'a';
    buff[s]++;
  }

  char maxstr = 'a';
  int maxnum = 0;
  for (int i = 0; i < 51; i++){
    if (buff[i] > maxnum){
      maxnum = buff[i];
      maxstr = i + 'a';
      cout << maxstr << " \n";
    }
  }
  return maxstr ? 2 * maxnum > letters.size() : '.';
}

int main(){
  string s = "ababac";
  run(s);
}
