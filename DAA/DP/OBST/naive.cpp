#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int>keys(n) , freq(n);
	for(int i = 0 ;i<n;i++){
		cin>>keys[i];
	}
	for(int i = 0 ;i<n;i++){
		cin>>freq[i];
	}

	int ans = INT_MAX;

	vector<vector<int>>cost(n , vector<int>(n, INT_MAX));
	for(int i = 0 ;i<n;i++){
		cost[i][i] = freq[i];
	}

	for(int len = 2 ; len<=n ; len++){
		for(int i = 0; i <= n-len; i++ ){
			int j = i + len -1;
			int count = 0;
			for(int k = i ;k<=j;k++){
				count+=freq[k];
			}
			int left = 0 , right = 0 , total = 0;
			for(int r = i ; r<=j;r++){
				if(r>i) left = cost[i][r-1];
				else left  =0;
				if(r<j) right = cost[r+1][j];
				else right = 0;

				total = left+right+count;

				if(total < cost[i][j]) cost[i][j] = total;
			}
		}
	}

	cout<<cost[0][n-1]<<endl;
	
}