#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 1; i <= n; i++)
#define maxN 30000

/*

input:
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 

*/


vector<int> st[4*maxN];

    void build(int ar[],int si,int ss,int se){
        if(ss==se){
            st[si].push_back(ar[ss]);
            return;
        }

        int mid=(ss+se)/2;
        build(ar,2*si,ss,mid);
        build(ar,2*si+1,mid+1,se);

        int i=0;
        int j=0;
        while(i < st[2*si].size() && j < st[2*si+1].size()){
            if(st[2*si][i] <= st[2*si+1][j]){
                st[si].push_back(st[2*si][i]);
                i++;
            }else {
                st[si].push_back(st[2*si+1][j]);
                j++;
            }

        }
        while(i<st[2*si].size())
        st[si].push_back(st[2*si][i]),i++;

        while(j<st[2*si+1].size())
        st[si].push_back(st[2*si+1][j]),j++;

    }

    int query(int si,int ss,int se,int l,int r,int k){
        if(ss > r || se< l) return 0;
        if(ss>=l && se<=r){
            
            int res = (st[si].size()-(lower_bound(st[si].begin() , st[si].end() , k) - st[si].begin()));
            return res;
        }
        int mid=(ss+se)/2;
        int left=query(2*si,ss,mid,l,r,k);
        int right=query(2*si+1,mid+1,se,l,r,k);
        return left+right;
    }


 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n,q,l,r,k;
    cin>>n;
    int ar[n];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    
    build(ar,1,1,n);
    cin>>q;
    while(q--){
        cin>>l>>r>>k;
        cout<<query(1,1,n,l,r,k)<<endl;
    }
}