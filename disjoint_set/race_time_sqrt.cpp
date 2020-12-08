#include<bits/stdc++.h>
using namespace std;
int bs=0;
vector<int> ar;
vector<vector<pair<int,int>>> block;

int query(int l,int r,int x){
    int count=0;
    //cout<<l<<" "<<r<<" "<<x<<endl;
    while(l%bs!=0 && l<=r){
        if(ar[l++]<=x) count++;
    }
    
    while(l+bs<=r){
       count+=lower_bound(block[l/bs].begin(),block[l/bs].end(),make_pair(x, (int)1e7))-block[l/bs].begin();
        l+=bs;
    }
    while(l<=r){
        if(ar[l++]<=r){
            count++;
        }
    }
    return count;

}


void update(int idx,int val){
    int b=idx/bs;

    for(int i=0;i<block[b].size();i++){

        if(block[b][i].second==idx){
            block[b][i].first=val;
            break;
        }
    }

    sort(block[b].begin(),block[b].end());
    ar[idx]=val;

}


void solve(){
    int n,q;
    cin>>n>>q;
    bs=(int)sqrt(n);

    //assingning size of array and block
    ar.resize(n,0);
    block.resize(bs+1);
    //taking array
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ar[i]=a;
        block[i/bs].push_back({a,i});
    }

    //sorting each block
    for(int i=0;i<block.size();i++)
    sort(block[i].begin(),block[i].end());


    while(q--){
        char c;
        cin>>c;
        if(c=='M'){
            int i,val;
            cin>>i>>val;
            i--;
            update(i,val);
        }else{
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            cout<<query(l,r,x)<<endl;
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
    solve();
    return 0;
}