#include <topcoder.h>


vector<string> split(string s, char delim){
  stringstream ss(s);
  string buff;
  vector<string> splited;
  while(getline(ss, buff, delim))
    splited.push_back(buff);
  return splited;
}

string run(string variableName){
  vector<string> splited = split(variableName, '_');
  string ret = splited[0];
  // PE(splited);
  for(int i = 1; i < splited.size(); i++){
    splited[i][0] = splited[i][0] + ('A' - 'a');
    ret += splited[i];
  }
  return ret;
}

int main(){
  P(run("sum_of_two_numbers"));
  P(run("variable"));
  P(run("t_o_p_c_o_d_e_r"));
  P(run("the_variable_name_can_be_very_long_like_this"));
}
