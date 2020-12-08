#include<bits/stdc++.h>
using namespace std;

typedef int item;


struct segTree{

    int size;
    vector<item> tree;

    item NEUTRAL_ELEMENT=INT_MIN;
    
    item merge(item a,item b){
        return max(a,b);
            
    }

    item single(int v){
       return v;
    }

    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);

    }

    void segment_tree(vector<int> &a,int lx,int rx,int x){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]=single(a[lx]);
            return ;
        }
        int m=(lx+rx)/2;
        segment_tree(a,lx,m,2*x+1);
        segment_tree(a,m,rx,2*x+2);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);

    }
    void build(vector<int> &a){
        segment_tree(a,0,size,0);
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


    void set1(int i,int v){
        update(i,v,0,size,0);
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

    item calc(int l,int r){
        return calc(l,r,0,size,0);  
    }


    int find(int k,int x,int lx,int rx){
        if(rx-lx==1){
            return lx;
        }

        int m=(lx+rx)/2;
        int sl=tree[2*x+1];
        if(k<sl){
            return find(k,2*x+1,lx,m);
        }else{
            return find(k-sl,2*x+2,m,rx);
        }

    }

    int find(int k){
        return find(k,0,0,size);
    }


    int first_above_x(int v,int l,int x,int lx,int rx){
        if(tree[x]<v) return -1;
        if(rx<=l)  return -1;
        if(rx-lx==1) return lx;

        int m=(lx+rx)/2;
        int res=first_above_x(v,l,2*x+1,lx,m);
        if(res==-1){
            res=first_above_x(v,l,2*x+2,m,rx);
        }
        return res;
    }


    int first_above_x(int v,int l){
        return first_above_x(v,l,0,0,size);
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
    st.build(a);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.set1(i,v);
        }else{
            int x,l;
            cin>>x>>l;
            cout<<st.first_above_x(x,l)<<"\n";
        }
        
    }
    return 0;
}