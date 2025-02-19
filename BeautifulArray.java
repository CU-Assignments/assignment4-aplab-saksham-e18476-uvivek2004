code:-
  '''
class Solution {
public:
    vector<int> beautifulArray(int n) {
    if (n == 1) return {1};
    
    vector<int> oddPart = beautifulArray((n + 1) / 2);
    vector<int> evenPart = beautifulArray(n / 2);
    
    vector<int> result;
    for (int num : oddPart) result.push_back(2 * num - 1);
    for (int num : evenPart) result.push_back(2 * num);
    
    return result;
    }
};

  '''
