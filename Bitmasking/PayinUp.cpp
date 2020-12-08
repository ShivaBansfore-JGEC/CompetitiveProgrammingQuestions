#include<bits/stdc++.h>
using namespace std;


bool isPossible(int arr[],int n,int k){
    int sum=0,i=0;
    while(n>0){
        (n&1)?sum+=arr[i]:sum+=0;
        i++;
        n=n>>1;
    }

    if(sum==k){
        return true;
    }else{
        return false;
    }

}

void solve(){
    int  n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int range=(1<<n)-1;
    for(int i=0;i<range;i++){
        if(isPossible(arr,i,k)){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}