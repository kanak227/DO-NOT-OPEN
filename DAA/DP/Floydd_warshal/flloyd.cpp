 #include <bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin>>n;
	const int INF = 1e9;

	vector<vector<int>>cost(n , vector<int>(n));
	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>cost[i][j];
			if(cost[i][j] == -1)
            cost[i][j] = INF;
		}
	}

	for(int via = 0; via<n; via++){
		for(int i = 0;i<n;i++){
			for(int j = 0; j<n;j++){
				if(cost[i][via] < INF && cost[via][j] < INF)
					cost[i][j] = min(cost[i][j] , cost[i][via]+cost[via][j]);
				
			}
		}
	}

	
	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){
			
			if(cost[i][j] != INF)
			    cout << cost[i][j];
			else
			    cout << "INF";
			
			cout << " ";
		}
		cout<<endl;
	}

}


// INDEXING VARIANCE
	
    // vector<vector<int>>cost(n , vector<int>(n , INF));
	// for(int i = 0 ;i<e;i++){
	// 	int s , d , w;
	// 	cin>>s>>d>>w;
	// 	cost[s-1][d-1] = w;
	// 	cost[i][i] = 0;
	// }



