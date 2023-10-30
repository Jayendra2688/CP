#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e2+5;
const ll W = 1e5+10;
ll dp[N][W];
ll solve(ll i,ll cap,vector<ll>&wt,vector<ll>&val){
    int n = wt.size();
    if(i==n || cap==0)
    return 0LL;
    if(dp[i][cap]!=-1)
    return dp[i][cap];
    if(wt[i]<=cap)
    dp[i][cap] = max(dp[i][cap],val[i]+solve(i+1,cap-wt[i],wt,val));
    dp[i][cap] = max(dp[i][cap],solve(i+1,cap,wt,val));
    return dp[i][cap];
}
ll solve1(ll cap,vector<ll>&wt,vector<ll>&val){
    int n = wt.size();
    vector<ll>dp1(cap+1,0);

    
    for(int i=n-1;i>=0;i--){
        vector<ll>dp2(cap+1,0);
        for(int j=1;j<=cap;j++){
            if(wt[i]<=j)
            dp2[j]= max(dp2[j],val[i]+dp1[j-wt[i]]);
            dp2[j]= max(dp2[j],dp1[j]);
        
        }
        // cout<<endl;
        dp1=dp2;
    }
    return dp1[cap];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n,cap;
    cin>>n>>cap;
    vector<ll>wt(n);
    vector<ll>val(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>val[i];
    }
    cout<<solve1(cap,wt,val)<<endl;
    return 0;
}