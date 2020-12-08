#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif

        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>m>>n;
            int arr[n];
            set<int> s;
            for(int i=0;i<n;i++){
                cin>>arr[i];
                s.insert(arr[i]);
            }
        ll temp[s.size()];
        ll k=0;
        set<int>::iterator it; 
        for (it = s.begin(); it != s.end(); ++it){
            temp[k]=*it;
            k++;
        } 
        


        ll odd=0,even=0;
        ll total=1<<n;
        for(int mask=1;mask<total;mask++){
            ll denom=1ll;
            ll set_bits=__builtin_popcount(mask);
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    denom*=temp[j];
                }
            }
            if(set_bits&1){
                odd+=(m/denom);
            }else
            {
                even+=(m/denom);
            }
            
        }
        cout<<odd-even<<endl;
    }
}
