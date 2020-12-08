#include<bits/stdc++.h>
#define BLOCK 555
using namespace std;

struct query{
 int l,r,i;
};

int ar[30001];
query Q[200001];
int ans[200001],fre[1000001];
int cnt=0;

bool comp(query a,query b){
    if(a.l/BLOCK!=b.l/BLOCK)
    return a.l/BLOCK<b.l/BLOCK;
    return a.r<b.r;
}

void add(int pos){
    fre[ar[pos]]++;
    if(fre[ar[pos]]==1)
    cnt++;
}

void remove(int pos){
    fre[ar[pos]]--;
    if(fre[ar[pos]]==0)
    cnt--;
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
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    
    int q;
    cin>>q;
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
        ans[Q[i].i]=cnt;

    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;

}