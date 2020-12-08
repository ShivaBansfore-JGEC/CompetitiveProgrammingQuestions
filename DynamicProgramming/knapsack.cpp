#include<bits/stdc++.h>
using namespace std;


int knapsack(int wts[],int price[],int n,int c){
    if(n==0 || c==0){
        return 0;
    }

    int inc=0;
    int exc=0;

    if(wts[n-1]<=c){
        inc=price[n-1]+knapsack(wts,price,n-1,c-wts[n-1]);
    }
    exc=0+knapsack(wts,price,n-1,c);
    return max(inc,exc);

}

void solve(){
    int capacity,n;
    cin>>n>>capacity;
    int wts[n];
    int price[n];


    for(int i=0;i<n;i++) cin>>wts[i];
    for(int i=0;i<n;i++) cin>>price[i];
    cout<<knapsack(wts,price,n,capacity)<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int t=1;
    while(t--) solve();

    return 0;
}