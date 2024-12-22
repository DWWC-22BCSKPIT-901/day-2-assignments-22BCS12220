#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Helper function for the dynamic programming solution
int dfs(int batchSize, vector<int>& remainders, int remainder, unordered_map<int, int>& memo) {
    int state = remainder;
    for (int i = 0; i < remainders.size(); ++i) {
        state = state * 31 + remainders[i]; // Unique hash for memoization
    }
    
    if (memo.find(state) != memo.end()) return memo[state];
    
    int maxHappy = 0;
    for (int i = 0; i < remainders.size(); ++i) {
        if (remainders[i] > 0) {
            remainders[i]--;
            int newRemainder = (remainder + i) % batchSize;
            maxHappy = max(maxHappy, dfs(batchSize, remainders, newRemainder, memo) + (newRemainder == 0 ? 1 : 0));
            remainders[i]++;
        }
    }
    
    return memo[state] = maxHappy;
}

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> remainders(batchSize, 0);
    int happyGroups = 0;
    
    // Count the remainders and count immediately happy groups
    for (int group : groups) {
        int remainder = group % batchSize;
        if (remainder == 0) {
            happyGroups++;
        } else {
            remainders[remainder]++;
        }
    }
    
    // Match complementary remainders to maximize happy groups
    for (int i = 1; i <= batchSize / 2; ++i) {
        if (i == batchSize - i) {
            happyGroups += remainders[i] / 2;
            remainders[i] %= 2;
        } else {
            int pairs = min(remainders[i], remainders[batchSize - i]);
            happyGroups += pairs;
            remainders[i] -= pairs;
            remainders[batchSize - i] -= pairs;
        }
    }
    
    unordered_map<int, int> memo;
    happyGroups += dfs(batchSize, remainders, 0, memo);
    return happyGroups;
}

int main() {
    int batchSize = 3;
    vector<int> groups = {1, 2, 3, 4, 5, 6};
    cout << "Maximum Happy Groups: " << maxHappyGroups(batchSize, groups) << endl;
    return 0;
}
