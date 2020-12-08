#include<bits/stdc++.h>
using namespace std;
int blk=0;
vector<int> ar;
vector<int> block;



int query(int l,int r){
    int sum=0;
    while(l<=r and l%blk!=0) sum+=ar[l++];

    while(l+blk<=r) sum+=block[l/blk],l+=blk;

    while(l<=r){
        sum+=ar[l++];
    }


return sum;
}


void update(int idx,int val){
    block[idx/blk]=(block[idx/blk]-ar[idx]+val);
    ar[idx]=val;
}


void solve(){
    int n,q,l,r,op,id,val;
    cin>>n>>q;
    ar.resize(n,0);
    blk=(int)sqrt(n);
    
    block.resize(blk+1,0);
    cout<<block.size()<<endl;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ar[i]=a;
        block[i/blk]+=a;
    }
    
    for(int i=0;i<block.size();i++){
        cout<<block[i]<<" ";
    }
    cout<<endl;
    while(q--){
        cin>>op;
        if(op==1){
            //update
            cin>>id>>val;
            update(id,val);
        }else{
            cin>>l>>r;
            cout<<query(l,r)<<endl;
        }
    }


}








int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}