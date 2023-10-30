#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int>dp(n,INT_MAX);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j=1;j<=k;j++){
            if(i+j>=n)
            break;
            dp[i] = min(dp[i],dp[i+j]+abs(v[i]-v[i+j]));
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}