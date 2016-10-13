#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class solution {
public:
  char findTheDiff(const string & s, const string & t) {
    vector<int> bucket_s(26,0), bucket_t(26,0);
    for (auto & ch : s)
      bucket_s[ch-'a']++;
    for (auto & ch : t)
      bucket_t[ch-'a']++;
    
    auto pr = std::mismatch(bucket_s.begin(), bucket_s.end(), bucket_t.begin());
    // std::cout << "first = " << *(pr.first) << ", second = " << *(pr.second) << std::endl;
    // std::cout << std::distance(bucket_s.begin(), pr.first) << std::endl;
    return char('a'+std::distance(bucket_s.begin(), pr.first));
  }
};

int main() {
  string s{"abcd"}, t{"abcde"};
  solution soln;
  std::cout << "The added letter is:\n";
  std::cout << soln.findTheDiff(s, t) << std::endl;
}
