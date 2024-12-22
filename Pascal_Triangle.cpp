#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalsTriangle(int numRows) {
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); // Initialize the row with 1s
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    return triangle;
}

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows = 5;
    vector<vector<int>> result = generatePascalsTriangle(numRows);
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    printTriangle(result);
    return 0;
}
