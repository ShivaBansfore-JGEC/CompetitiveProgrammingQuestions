#include<bits/stdc++.h>
using namespace std;
const int max_size=100001;
int ar[max_size];
int st [4*max_size];
int lazy_tree[4*max_size];

void build_tree(int x,int lx,int rx){
    if(lx==rx){
        st[x]=ar[lx];
        return;
    }
    int m=(lx+rx)/2;
    build_tree(2*x,lx,m);
    build_tree(2*x+1,m+1,rx);
    st[x]=st[2*x]+st[2*x+1];
}

int query(int si , int ss , int se , int qs , int qe)
{
	if(lazy_tree[si] != 0)
	{
		int dx = lazy_tree[si];
		lazy_tree[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy_tree[2*si] += dx , lazy_tree[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return 0;
 
	if(ss >= qs && se <= qe)
	return st[si];
 
	int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);

}
void update(int x,int lx,int rx,int l,int r,int val){
    if(lazy_tree[x]!=0){
        int dx=lazy_tree[x];
        st[x]+=dx*(rx-lx+1);
        lazy_tree[x]=0;
        if(lx!=rx){
            lazy_tree[2*x]+=dx;
            lazy_tree[2*x+1]+=dx;
        }
    }

    if(lx>=r || rx<=l ) return;

    if(lx>=l && rx<=r){
        int dx=(rx-lx+1)*val;
        st[x]+=dx;
        lazy_tree[2*x]+=val;
        lazy_tree[2*x+1]+=val;
        return ;
    }

    int m=(lx+rx)/2;
    update(2*x,lx,m,l,r,val);
    update(2*x+1,m+1,rx,l,r,val);
    st[x]=st[2*x]+st[2*x+1];
    

}


void printar(){
    for(int i=0;i<9;i++){
        cout<<st[i]<<" ";
    }
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
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            //query
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }else{
            //update
            int l,r,v;
            cin>>l>>r>>v;
            cout<<query(1,1,n,l,r)<<endl;
            update(1,1,n,l,r,v);
        }
    }
    return 0;

}