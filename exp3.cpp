#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int equalStacks(vector<int>& h1, vector<int>& h2, vector<int>& h3) {
    // Reverse the stacks to simplify popping from the top
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    
    // Calculate cumulative heights for each stack
    partial_sum(h1.begin(), h1.end(), h1.begin());
    partial_sum(h2.begin(), h2.end(), h2.begin());
    partial_sum(h3.begin(), h3.end(), h3.begin());
    
    // Initialize iterators for each stack
    auto it1 = h1.begin(), it2 = h2.begin(), it3 = h3.begin();
    
    // Find the common height by iterating until a common height is found or one of the stacks is empty
    while (it1 != h1.end() && it2 != h2.end() && it3 != h3.end()) {
        if (*it1 == *it2 && *it2 == *it3) {
            return *it1; // Common height found
        }
        // Pop from the tallest stack
        if (*it1 >= *it2 && *it1 >= *it3) {
            ++it1;
        } else if (*it2 >= *it1 && *it2 >= *it3) {
            ++it2;
        } else {
            ++it3;
        }
    }
    
    // If no common height found
    return 0;
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> h1(n1);
    vector<int> h2(n2);
    vector<int> h3(n3);

    for (int i = 0; i < n1; i++) {
        cin >> h1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> h2[i];
    }
    for (int i = 0; i < n3; i++) {
        cin >> h3[i];
    }

    int result = equalStacks(h1, h2, h3);
    cout << "Maximum possible common height: " << result << endl;

    return 0;
}
