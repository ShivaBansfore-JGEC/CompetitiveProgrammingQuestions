#include<bits/stdc++.h>
#define BLOCK 555
#define ll long long int
using namespace std;


struct query{
 int l,r,i;
};

int ar[200001];
query Q[200001];
ll ans[200001];
int fre[1000001];
ll power=0;

bool comp(query a,query b){
    if(a.l/BLOCK!=b.l/BLOCK)
    return a.l/BLOCK<b.l/BLOCK;
    return a.r<b.r;
}

void add(int pos){
    ll cnt=fre[ar[pos]];
    fre[ar[pos]]++;
    power-=(cnt*cnt)*ar[pos],cnt++;
    power+=(cnt*cnt)*ar[pos];
    
    cnt++;
}

void remove(int pos){
    ll cnt=fre[ar[pos]];
    fre[ar[pos]]--;
    power-=(cnt*cnt)*ar[pos],cnt--;
    power+=(cnt*cnt)*ar[pos];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r;
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

        ans[Q[i].i]=power;

    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;

}