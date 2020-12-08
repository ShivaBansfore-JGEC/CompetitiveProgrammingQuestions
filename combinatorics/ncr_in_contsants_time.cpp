#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000001;

// time o(10^6) for precomputing and o(1) for query

ll factotialNumInverse[N+1];

ll naturalNumInv[N+1];

ll fact[N+1];

void inverseOfNum(ll p){
    naturalNumInv[0]=naturalNumInv[1]=1;
    for(int i=2;i<=N;i++){
        naturalNumInv[i]=naturalNumInv[p%i]*(p-p/i)%p;
    }
}

void inverseFactorial(ll p){
    factotialNumInverse[0]=factotialNumInverse[1]=1;
    for(int i=2;i<=N;i++){
        factotialNumInverse[i]=(naturalNumInv[i]* factotialNumInverse[i-1])%p;
    }
}

void factorial(ll p){
    fact[0]=1;
    for(int i=1;i<=N;i++){
        fact[i]=(fact[i-1]*i)%p;
    }

}

ll binomial(ll n,ll r,ll p){
    ll ans=((fact[n]*factotialNumInverse[r])%p*factotialNumInverse[n-r])%p;
    return ans;
}

int main(){
    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
        ll p=1000000007;
        inverseOfNum(p);
        inverseFactorial(p);
        factorial(p);
        int t;
		cin>>t;
		while(t--){
			int n,m,k;
			cin>>n>>m>>k;
			cout<<binomial(abs(n-k),m,p)<<endl;
		}
    cout<<(1<<9);
return 0;

}