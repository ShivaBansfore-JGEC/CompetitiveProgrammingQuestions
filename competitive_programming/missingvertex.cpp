#include <bits/stdc++.h>
using namespace std;

int ncr(int n,int k){
    int dp[k+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int j=min(i,k);
        while ( j>0)
        {
            dp[j]=dp[j]+dp[j-1];
            j--;
        }
        
    }
    return dp[k];
}
int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int t;
    cin>>t;
    while (t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<ncr(4,4)<<endl;
    }
    

}