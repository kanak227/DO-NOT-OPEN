#include <bits/stdc++.h>
using namespace std;
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int r = 0;

        while(r < n-1){
            int far = 0;
            for(int i = l ; i <= r ; i++){
                far = max(far , i+nums[i]);
            }
            ans++;
            l = r+1;
            r = far;
        }
        return ans;

    }

    int main(){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
        }
        cout<<jump(nums)<<endl;
    }