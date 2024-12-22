#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        // Calculate the area between the two lines
        int width = right - left;
        int currentArea = min(height[left], height[right]) * width;
        maxWater = max(maxWater, currentArea);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum Water Container: " << maxArea(height) << endl;
    return 0;
}
