#include<bits/stdc++.h>
#define BLOCK 555
using namespace std;
 
struct query{
 int l,r,i,k;
};
 
int ar[300002];
query Q[300002];
int ans[300002],fre[300001];
int cnt=0;
vector<int> v;
bool comp(query a,query b){
    if(a.l/BLOCK!=b.l/BLOCK)
    return a.l/BLOCK<b.l/BLOCK;
    return a.r<b.r;
}
 
void add(int pos){
    fre[ar[pos]]++;
    if(fre[ar[pos]]==1)
    v.push_back(ar[pos]);
}
 
void remove(int pos){
    fre[ar[pos]]--;
    if(fre[ar[pos]]==0)
    v.erase(remove(v.begin(), v.end(),ar[pos]), v.end()); 
}
 
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
    int n,q,k;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r>>Q[i].k;
            Q[i].i=i,Q[i].l--,Q[i].r--;
    }
 
    sort(Q,Q+q,comp);
    int ml=0,mr=-1;
    for(int i=0;i<q;i++){
 
        int l=Q[i].l;
        int r=Q[i].r;
 
        while(ml>l){
          ml--,add(ml);  
        }
 
        while(mr<r){
            mr++,add(mr);
        }
 
        while(ml<l)
        remove(ml),ml++;
 
        while(mr>r)
        remove(mr),mr--;

        int res=-1;
        int bound=(r-l+1)/Q[i].k;
        for(int i=0;i<v.size();i++){
            if(fre[v[i]]>bound){
                res=v[i];
                break;
                
            }
        }
        ans[Q[i].i]=res;
 
    }
 
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
 
} 