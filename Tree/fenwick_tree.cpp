#include<bits/stdc++.h>
using namespace std;
vector<int> ar(100);
vector<int> tree(100);

int sum(int idx){
    int s=0;
    while(idx>0){
        s+=tree[idx];
        idx-=(idx & -idx);
    }
    return s;
}


void update(int idx,int val,int n){
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        update(i,ar[i],n);
    }
    int q;
    cin>>q;
    while (q--)
    {
        int v;
        cin>>v;
        cout<<sum(v)<<endl;
    }
    int l,r;
    cin>>l>>r;
    cout<<sum(r)-sum(l-1)<<endl;


    return 0;
}