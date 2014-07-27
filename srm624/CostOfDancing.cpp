#include <iostream>
#include <vector>

using namespace std;

//#define EACH()

class CostOfDancing {
public:
  int minimun(int K, vector<int> danceCost){
    sort(danceCost.begin(), danceCost.end());
    int sum = 0;
    for (int i = 0; i < K; i++)
      sum += danceCost[i];
    return sum;
  }
};

int main(){
  CostOfDancing c;
  int a[] = {1, 5, 3, 4};
  vector<int> v(a, a + 4);
  cout << c.minimun(2, v) << endl;

  int a1[] = {1, 5, 4};
  vector<int> v1(a1, a1 + 3);
  cout << c.minimun(3, v1) << endl;

  int a2[] = {2, 2, 4, 5, 3};
  vector<int> v2(a2, a2 + 5);
  cout << c.minimun(1, v2) << endl;

  int a3[] = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932, 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};
  vector<int> v3(a3, a3 + sizeof(a3)/(sizeof(a3[0])));
  cout << c.minimun(39, v3) << endl;
  
}
