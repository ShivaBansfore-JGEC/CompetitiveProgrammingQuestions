#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
typedef long long ll;

ll power(int a,int n){
    ll res=1;
    while(n){
        if (n%2){
            res*=a%mod;
            n--;
        }
        a*=a;
        n/=2;
    }
    return res%mod;
}
int ncr(int n,int k){
    int dp[k+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int j=min(i,k);
        while(j>0){
            dp[j]=(dp[j]+dp[j-1]);
            j--;
        }
    }
    return dp[k];

}
//dp solution 
int dp[10001]={0};
void catlan(){
    dp[0]=dp[1]=1;
    for(int i=2;i<=1000;i++){
        for(int j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1])%mod;
        }
    }
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int t;
    cin>>t;
    catlan();
    while(t>0){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
        t--;
    }



    return 0;
}