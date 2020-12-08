#include<bits/stdc++.h>
using namespace std;



struct item{
    int m,c;
};

struct segTree{

    int size;
    vector<item> tree;

    item NEUTRAL_ELEMENT={INT_MAX,0};
    
    item merge(item a,item b){
        if(a.m<b.m) return a;
        if(a.m>b.m) return b;
        return {a.m,a.c+b.c};
    }

    item single(int v){
        return {v,1};
    }

    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);

    }

    void segment_tree(vector<int> &a,int lx,int rx,int x){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]={a[lx],1};
            return ;
        }
        int m=(lx+rx)/2;
        segment_tree(a,lx,m,2*x+1);
        segment_tree(a,m,rx,2*x+2);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);

    }


    void update(int i,int val,int lx,int rx,int x){
        if(rx-lx==1){
            tree[x]=single(val);
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            update(i,val,lx,m,2*x+1);
        }else{
            update(i,val,m,rx,2*x+2);
        }
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }


    void set1(int i,int v,int n){
        update(i,v,0,n,0);
    }

    item calc(int l,int r,int lx,int rx,int x){
            //completely outside
            if(lx>=r || l>=rx) return NEUTRAL_ELEMENT;

            //completely inside

            if(lx>=l && rx<=r) return tree[x];

            int m=(lx+rx)/2;
            item s1=calc(l,r,lx,m,2*x+1);
            item s2=calc(l,r,m,rx,2*x+2);
            return merge(s1,s2);
    }

    item calc(int n,int l,int r){
        return calc(l,r,0,n,0);
        
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
            auto res=st.calc(n,l,r);
            cout<<res.m<<" "<<res.c<<endl;
        }
    }
    return 0;
}