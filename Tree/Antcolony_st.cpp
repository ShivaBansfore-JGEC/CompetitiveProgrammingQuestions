#include<bits/stdc++.h>
using namespace std;
int st[200002];
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
}



struct segTree{

    int size;
    vector<int> tree;
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
        tree[x]=min(tree[2*x+1],tree[2*x+2]);

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
        tree[x]=min(tree[2*x+1],tree[2*x+2]);
    }


    void set1(int i,int v,int n){
        update(i,v,0,n,0);
    }

    int calc(int l,int r,int lx,int rx,int x){
            //completely outside
            if(lx>=r || l>=rx) return INT_MAX;

            //completely inside

            if(lx>=l && rx<=r) return tree[x];

            int m=(lx+rx)/2;
            int s1=calc(l,r,lx,m,2*x+1);
            int s2=calc(l,r,m,rx,2*x+2);
            return min(s1,s2);
    }

    int calc(int n,int l,int r){
        int s1=calc(l,r,0,n,0);
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
    int n;
    cin>>n;
    segTree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    st.segment_tree(a,0,n,0);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;

        int ar[r-l+1];
        int j=0;
        for(int i=l-1;i<r;i++){
            ar[j]=a[i];
            j++;
        }
        
        int min=st.calc(l-1,r,0,n,0);
        int gcd=findGCD(ar,r-l+1);

        int nvr=0;
        for(int i=0;i<(r-l+1);i++){
            if(ar[i]==min){
                nvr++;
            }
        }
        if(gcd==min){
            cout<<r-l+1-nvr<<endl;
        }else{
            cout<<r-l+1<<endl;
        }
        
    }
    return 0;
}
