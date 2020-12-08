#include<bits/stdc++.h>
using namespace std;
int dp[100];
int ladder(int n,int k){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    int count=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            count=count+ladder(n-i,k);
        }
    }
    return dp[n]=count;
}

int bottom_up_ladder(int n,int k){
    int dp[n+1];
    for(int i=0;i<n;i++) dp[i]=0;
    dp[0]=1;

    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];

}

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<100;i++){
        dp[i]=-1;
    } 
    cout<<ladder(n,k)<<endl;
    cout<<bottom_up_ladder(n,k);
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int t=1;
    //cin>>t;
    while(t--) solve();

    return 0;
}