#include<bits/stdc++.h>
using namespace std;
#define  blk 316
int ar[100001];
int F[blk];

struct query{
    int l,r,i;
};
query Q[100001];
map<int,int> fre;

bool compare(query a,query b){
    if(a.l/blk!=b.l/blk)
        return a.l/blk<b.l/blk;
    else return a.r<b.r;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    cout<<int(sqrt(100001));
    int n,m,q,l,r;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i,Q[i].l--,Q[i].r--;

    }
    sort(Q,Q+q,compare);

    return 0;
}