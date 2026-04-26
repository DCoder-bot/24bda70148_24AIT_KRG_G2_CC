#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int totalOnes = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) totalOnes++;
    }

    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        int val = (a[i] == 0) ? 1 : -1;

        currSum = max(val, currSum + val);
        maxSum = max(maxSum, currSum);
    }

    cout << totalOnes + maxSum << endl;

    return 0;
}