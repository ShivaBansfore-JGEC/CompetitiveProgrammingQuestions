#include<bits/stdc++.h>
using namespace std;


struct segTree{

    int size;
    vector<long long> tree;
    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.assign(2*size,0);

    }

    void segment_tree(vector<int> &a,int lx,int rx,int x){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]=a[lx];
            return ;
        }
        int m=(lx+rx)/2;
        segment_tree(a,lx,m,2*x+1);
        segment_tree(a,m,rx,2*x+2);
        tree[x]=tree[2*x+1]+tree[2*x+2];

    }


    void update(int i,int val,int lx,int rx,int x){
        if(rx-lx==1){
            tree[x]=val;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            update(i,val,lx,m,2*x+1);
        }else{
            update(i,val,m,rx,2*x+2);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }


    void set1(int i,int v,int n){
        update(i,v,0,n,0);
    }

    long long sum(int l,int r,int lx,int rx,int x){
            //completely outside
            if(lx>=r || l>=rx) return 0;

            //completely inside

            if(lx>=l && rx<=r) return tree[x];

            int m=(lx+rx)/2;
            long long s1=sum(l,r,lx,m,2*x+1);
            long long s2=sum(l,r,m,rx,2*x+2);
            return s1+s2;
    }

    long long sum1(int n,int l,int r){
        long long s1=sum(l,r,0,n,0);
        return s1;
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
    int n,m;
    cin>>n>>m;
    segTree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    st.segment_tree(a,0,n,0);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.set1(i,v,n);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.sum1(n,l,r)<<endl;
        }
    }
    return 0;
}