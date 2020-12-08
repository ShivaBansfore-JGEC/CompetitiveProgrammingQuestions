#include<bits/stdc++.h>
using namespace std;

int dp[100];
int min_coin(int coins[],int n,int amount){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(amount-coins[i]>=0){
                ans=min(ans,min_coin(coins,n,amount-coins[i])+1);
            }
        }
        return dp[amount]=ans;
}

int max_coin(int coins[],int n,int amount){
    if(amount==0){
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(amount-coins[i]>=0){
            ans=max(ans,max_coin(coins,n,amount-coins[i])+1);
        }
    }
    return ans;
}

int min_coin_bottom(int coins[],int n,int amount){
    int dp[amount+1];
    for(int i=0;i<=amount;i++) dp[i]=INT_MAX;
    dp[0]=0;

    for(int r=1;r<=amount;r++){
        for(int i=0;i<n;i++){
            if(coins[i]<=amount){
                dp[r]=min(dp[r],dp[r-coins[i]]+1);
            }
        }
    }
    return dp[amount];
}


void solve(){
    int amount,n;
    cin>>amount>>n;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    for(int i=0;i<amount+1;i++){
        dp[i]=-1;
    }
    cout<<min_coin(coins,n,amount)<<endl;
    cout<<max_coin(coins,n,amount)<<endl;
    cout<<min_coin_bottom(coins,n,amount)<<endl;

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