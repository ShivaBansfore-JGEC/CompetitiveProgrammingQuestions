#include<bits/stdc++.h>
using namespace std;
const int max_size=100001;
int st [4*max_size];
int lazy_tree[4*max_size];

void build_tree(int ar[],int x,int lx,int rx){
    if(lx==rx){
        st[x]=ar[lx];
        return;
    }
    int m=(lx+rx)/2;
    build_tree(ar,2*x,lx,m);
    build_tree(ar,2*x+1,m+1,rx);
    st[x]=min(st[2*x],st[2*x+1]);
}

int query(int si , int ss , int se , int qs , int qe)
{
	if(lazy_tree[si] != 0)
	{
		int dx = lazy_tree[si];
		lazy_tree[si] = 0;
		st[si] += dx;
 
		if(ss != se)
		lazy_tree[2*si] += dx , lazy_tree[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return INT_MAX;
 
	if(ss >= qs && se <= qe)
	return st[si];
 
	int mid = (ss + se) / 2;
	return min(query(2*si , ss , mid , qs , qe),query(2*si+1 , mid+1 , se , qs , qe));

}
void update(int x,int lx,int rx,int l,int r,int val){
    if(lazy_tree[x]!=0){
        int dx=lazy_tree[x];
        st[x]+=dx;
        lazy_tree[x]=0;
        if(lx!=rx){
            lazy_tree[2*x]+=dx;
            lazy_tree[2*x+1]+=dx;
        }
    }

    if(lx>=r || rx<=l ) return;

    if(lx>=l && rx<=r){
        int dx=val;
        st[x]+=dx;
        lazy_tree[2*x]+=val;
        lazy_tree[2*x+1]+=val;
        return ;
    }

    int m=(lx+rx)/2;
    update(2*x,lx,m,l,r,val);
    update(2*x+1,m+1,rx,l,r,val);
    st[x]=min(st[2*x],st[2*x+1]);
    

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

	int n;
	cin>>n;

    for(int i=0;i<2*n;i++){
        st[i]=INT_MAX;
    }
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    build_tree(a,1,1,n);
    for(int i=0;i<2*n;i++){
        cout<<st[i]<<" ";
    }
	int q;
	cin>>q;
	while (q--)
	{
		int l,r,d;
		cin>>l>>r;
		if (cin.get()==10)
		{
			if (l<=r) cout<<query(1,1,n,l,r)<<endl;
			else cout<<min(query(1,1,n,0,r),query(1,1,n,l,n-1))<<endl;
		}
		else
		{
			cin>>d;
			if (l<=r) update(1,1,n,l,r,d);
			else update(1,1,n,0,r,d),update(1,1,n,l,n-1,d);
		}
	}

    for(int i=0;i<2*n;i++){
        cout<<st[i]<<" ";
    }
    return 0;

}