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
    return res;
}

//NAIVE APPROACH TO COUNT SET BITS TIME-THETA OF LOGN
unsigned int countsetbits(unsigned int n){
    unsigned int count=0;
    while (n)
    {
     count+=n&1;
     n>>=1;   
    }
    return count;
    
}

//recursive apprach
int countbits(int n){
    if(n==0) return 0;
    return (n&1)+countsetbits(n>>1);
}



//Brian Kernighan’s Algorithm: time-logn
unsigned int count_bits(unsigned int n){
    unsigned int count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}


int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    //cout<<countsetbits(15)<<endl;
    //cout<<countbits(15)<<endl;
    int t;
    cin>>t;  
    while(t--){
        int v;
        cin>>v;
        int n=count_bits(v);
    int odd=power(2,n);
    cout<<(v+1)-odd<<" "<<odd<<endl;
    }
    
    return 0;
}