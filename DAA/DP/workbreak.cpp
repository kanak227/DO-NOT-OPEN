#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_set<string> dict;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        dict.insert(word);
    }

    string s;
    cin >> s;

    int len = s.size();

    vector<int> dp(len + 1, 0);
    dp[0] = 1;  // empty string is valid

    for(int i = 1; i <= len; i++){
        for(int j = 0; j < i; j++){
            if(dp[j]){
                string sub = s.substr(j, i - j);

                if(dict.count(sub)){
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    cout << dp[len] << endl;

    return 0;
}