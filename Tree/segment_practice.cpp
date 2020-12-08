
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg_tree{
    vector<long long> tree;
    int size;

    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.assign(2*size,0);
    }



    void build_tree(vector<int> &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]=a[lx];
            return;
        }

        int m=(lx+rx)/2;
        build_tree(a,2*x+1,lx,m);
        build_tree(a,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];

    }
    void build_tree(vector<int> &a){
        build_tree(a,0,0,size);
    }

    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=v;
            return;
        }

        int m=(lx+rx)/2;
        if(i<m){
            update(i,v,2*x+1,lx,m);
        }else{
            update(i,v,2*x+2,m,rx);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }

    void update(int i,int v){
        update(i,v,0,0,size);
    }

    long long sum(int x,int lx,int rx,int l,int r){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r) return tree[x];

        int m=(lx+rx)/2;
        long long s1=sum(2*x+1,lx,m,l,r);
        long long s2=sum(2*x+2,m,rx,l,r);
        return s1+s2;

    }
    long long sum(int l,int r){
       return sum(0,0,size,l,r);
    }





    void printTree(){
        for(int i=0;i<size;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    seg_tree st;
    st.init(n);
    st.build_tree(a);

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.update(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<endl;
        }
    }
    

    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item{
    int m,c;
};

struct seg_tree{
    vector<item> tree;
    int size;

    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);
    }
    item NEUTRAL_ELEMENT={INT_MAX,0};
    item merge(item a,item b){
        if(a.m>b.m) return b;
        if(a.m<b.m) return a;
        return {a.m,a.c+b.c};

    }
    item single(int v){
        return {v,1};
    }

    void build_tree(vector<int> &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]=single(a[lx]);
            return;
        }

        int m=(lx+rx)/2;
        build_tree(a,2*x+1,lx,m);
        build_tree(a,2*x+2,m,rx);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);

    }
    void build_tree(vector<int> &a){
        build_tree(a,0,0,size);
    }

    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=single(v);
            return;
        }

        int m=(lx+rx)/2;
        if(i<m){
            update(i,v,2*x+1,lx,m);
        }else{
            update(i,v,2*x+2,m,rx);
        }
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }

    void update(int i,int v){
        update(i,v,0,0,size);
    }

    item mini(int x,int lx,int rx,int l,int r){
        if(lx>=r || rx<=l) return NEUTRAL_ELEMENT;
        if(lx>=l && rx<=r) return tree[x];

        int m=(lx+rx)/2;
        item s1=mini(2*x+1,lx,m,l,r);
        item s2=mini(2*x+2,m,rx,l,r);
        return merge(s1,s2);

    }
    item minimum(int l,int r){
       return mini(0,0,size,l,r);
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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    seg_tree st;
    st.init(n);
    st.build_tree(a);

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.update(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            auto res=st.minimum(l,r);
            cout<<res.m<<" "<<res.c<<endl;
        }
    }
    

    return 0;
}
*/


//SEGMENT TREE MIN QUERY
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg_tree{
    vector<int> tree;
    int size;

    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.assign(2*size,0);
    }



    void build_tree(vector<int> &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]=a[lx];
            return;
        }

        int m=(lx+rx)/2;
        build_tree(a,2*x+1,lx,m);
        build_tree(a,2*x+2,m,rx);
        tree[x]=min(tree[2*x+1],tree[2*x+2]);

    }
    void build_tree(vector<int> &a){
        build_tree(a,0,0,size);
    }

    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=v;
            return;
        }

        int m=(lx+rx)/2;
        if(i<m){
            update(i,v,2*x+1,lx,m);
        }else{
            update(i,v,2*x+2,m,rx);
        }
        tree[x]=min(tree[2*x+1],tree[2*x+2]);
    }

    void update(int i,int v){
        update(i,v,0,0,size);
    }

    int mini(int x,int lx,int rx,int l,int r){
        if(lx>=r || rx<=l) return INT_MAX;
        if(lx>=l && rx<=r) return tree[x];

        int m=(lx+rx)/2;
        int s1=mini(2*x+1,lx,m,l,r);
        int s2=mini(2*x+2,m,rx,l,r);
        return min(s1,s2);

    }
    int minimum(int l,int r){
       return mini(0,0,size,l,r);
    }


    void printTree(){
        for(int i=0;i<size;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    seg_tree st;
    st.init(n);
    st.build_tree(a);

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.update(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.minimum(l,r)<<endl;
        }
    }
    

    return 0;
}

*/









//SIMPLE SEGMENT TREE
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg_tree{
    vector<long long> tree;
    int size;

    void init(int n){
        size=1;
        while(size<n) size*=2;
        tree.assign(2*size,0);
    }



    void build_tree(vector<int> &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx< (int) a.size())
                tree[x]=a[lx];
            return;
        }

        int m=(lx+rx)/2;
        build_tree(a,2*x+1,lx,m);
        build_tree(a,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];

    }
    void build_tree(vector<int> &a){
        build_tree(a,0,0,size);
    }

    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=v;
            return;
        }

        int m=(lx+rx)/2;
        if(i<m){
            update(i,v,2*x+1,lx,m);
        }else{
            update(i,v,2*x+2,m,rx);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }

    void update(int i,int v){
        update(i,v,0,0,size);
    }

    long long sum(int x,int lx,int rx,int l,int r){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r) return tree[x];

        int m=(lx+rx)/2;
        long long s1=sum(2*x+1,lx,m,l,r);
        long long s2=sum(2*x+2,m,rx,l,r);
        return s1+s2;

    }
    long long sum(int l,int r){
       return sum(0,0,size,l,r);
    }





    void printTree(){
        for(int i=0;i<size;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    seg_tree st;
    st.init(n);
    st.build_tree(a);

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.update(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<endl;
        }
    }
    

    return 0;
}
*/