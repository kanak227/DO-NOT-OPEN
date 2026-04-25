#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int target, vector<int>& arr,
           vector<int>& curr, int sum, bool &found) {

    // if sum matches target → print
    if (sum == target) {
        found = true;
        cout << "[";
        for (int i = 0; i < curr.size(); i++) {
            cout << curr[i];
            if (i != curr.size() - 1) cout << " ";
        }
        cout << "]" << endl;
        return;
    }

    // stop conditions
    if (idx == arr.size() || sum > target) return;

    // 🔹 TAKE
    curr.push_back(arr[idx]);
    solve(idx + 1, target, arr, curr, sum + arr[idx], found);
    curr.pop_back(); // backtrack

    // 🔹 NOT TAKE
    solve(idx + 1, target, arr, curr, sum, found);
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> curr;
    bool found = false;

    solve(0, target, arr, curr, 0, found);

    if (!found) {
        cout << "No subset found";
    }

    return 0;
}