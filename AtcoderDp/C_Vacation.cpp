#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>grid[i][j];
        }
    }
    
    vector<int>dp1(4,0);
    
    for(int i=n-1;i>=0;i--){
        vector<int>dp2(4,INT_MIN);
        for(int prev=3;prev>=0;prev--){
            for(int j=0;j<=2;j++){
                if(prev!=j){
                    dp2[prev]=max(dp2[prev],grid[i][j]+dp1[j]);
                    // cout<<"hi"<<endl;
                }
            }
        }
        dp1=dp2;
    }
    cout<<dp1[3]<<endl;

    return 0;
}