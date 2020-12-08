#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(int a,int n){
    ll res=1;
    while(n){
        if (n%2){
            res*=a;
            n--;
        }
        a*=a;
        n/=2;
    }
}

ll modInv(int n ,int k){
    return power(n,k-2);
}


ll ncrModfermat(int n,int r,int p){
    if(r==0) return 1;
    ll fact[n+1]={0};
    fact[0]=1;
    for(int i=0;i<=n;i++){
        fact[i]=(ll) fact[i-1]*(ll)i;
    }

    return (fact[n]*modInv(fact[r],p)%p*modInv(fact[n-r],p)%p)%p;
}
int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int n,r,p;
    cin>>n>>r>>p;
    cout<<ncrModfermat(n,r,p)<<endl;
}