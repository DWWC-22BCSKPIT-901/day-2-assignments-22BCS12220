#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate
using namespace std;

bool canDistribute(const vector<int>& jobs, vector<int>& workers, int idx, int limit) {
    if (idx == jobs.size()) return true; 

    for (int i = 0; i < workers.size(); ++i) {
        if (workers[i] + jobs[idx] > limit) continue;  
        workers[i] += jobs[idx]; 
        if (canDistribute(jobs, workers, idx + 1, limit)) return true;

        workers[i] -= jobs[idx]; 

        if (workers[i] == 0) break; 
    }
    return false; 
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend()); 
    int low = jobs[0]; 
    int high = accumulate(jobs.begin(), jobs.end(), 0); 

    while (low < high) {
        int mid = low + (high - low) / 2;
        vector<int> workers(k, 0); 

        if (canDistribute(jobs, workers, 0, mid)) {
            high = mid; 
        } else {
            low = mid + 1; 
        }
    }
    return low; 
}

int main() {
    vector<int> jobs = {3, 2, 3};
    int k = 3;
    cout << "Minimum Possible Maximum Working Time: " << minimumTimeRequired(jobs, k) << endl;
    return 0;
}
