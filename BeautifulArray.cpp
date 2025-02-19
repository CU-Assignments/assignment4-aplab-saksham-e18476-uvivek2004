code:-
  '''
#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int n) {
    if (n == 1) return {1};
    
    vector<int> oddPart = beautifulArray((n + 1) / 2);
    vector<int> evenPart = beautifulArray(n / 2);
    
    vector<int> result;
    for (int num : oddPart) result.push_back(2 * num - 1);
    for (int num : evenPart) result.push_back(2 * num);
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = beautifulArray(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

  '''
