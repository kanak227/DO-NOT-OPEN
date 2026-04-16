#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum;
	cin>>sum;

	int n;
	cin>>n;

	vector<int>arr(n);
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}

	vector<int>dp(sum+1 ,0);
	dp[0] = 1;
	for(int a : arr){
		for(int i = a ;i<=sum;i++){
			dp[i] += dp[i-a];
		}
	}

	cout<<dp[sum];
	
}