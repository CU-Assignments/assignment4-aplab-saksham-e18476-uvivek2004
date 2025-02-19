code:-
  '''
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    for (auto& b : buildings) {
        events.push_back({b[0], -b[2]}); // Start of building (negative height)
        events.push_back({b[1], b[2]});  // End of building (positive height)
    }

    sort(events.begin(), events.end()); // Sort by x-coordinates

    multiset<int> heights = {0}; // Track active building heights
    vector<vector<int>> result;
    int prevHeight = 0;

    for (auto& [x, h] : events) {
        if (h < 0) 
            heights.insert(-h); // Add new building height
        else 
            heights.erase(heights.find(h)); // Remove ending building height

        int currHeight = *heights.rbegin(); // Max height at current x
        if (currHeight != prevHeight) { // Only add if height changes
            result.push_back({x, currHeight});
            prevHeight = currHeight;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skyline = getSkyline(buildings);

    for (auto& point : skyline) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    return 0;
}


  '''
