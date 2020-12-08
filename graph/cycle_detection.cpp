#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[100];
bool visited[100];

bool dfs(int u,int p){
    visited[u]=true;
    for(auto c:graph[u]){
        if(!visited[c]){
            if(dfs(c,u)==true)
            return true;

        }else{
            if(c!=p) return true;
        }
    }
    return false;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    cout<<dfs(1,0)<<endl;

}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}