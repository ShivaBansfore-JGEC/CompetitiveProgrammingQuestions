#include<bits/stdc++.h>
using namespace std;
int s[100],T[100],FT[200];
int timer;
vector<int> tree[100];

void dfs(int node,int par){
    s[node]=timer;
    FT[timer]=node;
    timer++;
    for(int child:tree[node]){
        if(child!=par){
            dfs(child,node);
        }
    }

    T[node]=timer;
    FT[timer]=node;
    timer++;
    
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
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
    }
    dfs(1,0);
    while(q--){
        int t,v;
        cin>>t>>v;
        if(t==1){
            if(FT[v-1]!=0){
                FT[v-1]=0;
            }else
            {
                FT[v-1]=v;
            }
            
        }else
        {
            int se=s[v];
            int ee=T[v];
            int c=0;
            for(int i=se+1;i<ee;i++){
                if(FT[i]!=0){
                    c++;
                }
            }
            cout<<c<<endl;

        
        }
        
    }
    return 0;

}