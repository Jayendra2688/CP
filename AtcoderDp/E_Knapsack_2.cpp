#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long N = 1e2+1;
const long long V = 1e5+1;

long long solve1(long long cap,vector<long long>&wt,vector<long long>&val){
    long long n = wt.size();
    vector<long long>dp1(1e5+1,1e15);
    dp1[0]=0;
    for(long long i=n-1;i>=0;i--){
        vector<long long>dp2(1e5+1,1e15);
        dp2[0]=0;
        for(long long j=1;j<=1e5;j++){
            if(val[i]<=j){
                dp2[j] = min(dp2[j],wt[i]+dp1[j-val[i]]);
            }
            dp2[j] = min(dp2[j],dp1[j]);
        }
        dp1=dp2;
    }
    for(long long i=1e5;i>=0;i--){
        if(dp1[i]<=cap)
        return i;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,cap;
    cin>>n>>cap;
    vector<long long>val(n);
    vector<long long>wt(n);
    for(long long i=0;i<n;i++){
        cin>>wt[i];
        cin>>val[i];
    }
    cout<<solve1(cap,wt,val)<<endl;
    return 0;
}