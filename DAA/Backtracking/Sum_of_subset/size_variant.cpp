#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int target, int k,
           vector<int>& arr, vector<int>& curr,
           int sum) {

    // valid subset
    if (sum == target && curr.size() <= k) {
        cout << "[";
        for (int i = 0; i < curr.size(); i++) {
            cout << curr[i];
            if (i != curr.size() - 1) cout << " ";
        }
        cout << "]" << endl;
        return;
    }

    // stop conditions
    if (idx == arr.size() || sum > target || curr.size() > k)
        return;

    // 🔹 TAKE
    curr.push_back(arr[idx]);
    solve(idx + 1, target, k, arr, curr, sum + arr[idx]);
    curr.pop_back(); // backtrack

    // 🔹 NOT TAKE
    solve(idx + 1, target, k, arr, curr, sum);
}

int main() {
    int n, target, k;
    cin >> n >> target >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> curr;

    solve(0, target, k, arr, curr, 0);

    return 0;
}