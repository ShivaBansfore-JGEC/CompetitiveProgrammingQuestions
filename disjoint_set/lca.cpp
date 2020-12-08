#include<bits/stdc++.h>
using namespace std;
int bs=0;
vector<vector<int>> Tree;
vector<int> depth,parent,blockParent;
int height=0;





void dfs1(int src,int level,int par){
    depth[src]=par;
    parent[src]=par;
    height=max(height,level);
    for(int ch:Tree[src]){
        dfs1(ch,level+1,src);
    }
}

void dfs2(int src,int par){

    int d1=depth[src];
    int d2=depth[par];

    if(d1/bs==d2/bs){
        parent[src]=blockParent[par];
    }else{
        blockParent[src]=parent[src];
    }
}

int lca(int u,int v){
    
    while(blockParent[u]!=blockParent[v]){
            if(depth[u] > depth[v]){
               swap(u,v);
            }
            v=blockParent[v];
    }

    while(u!=v){

        if(depth[u] > depth[v]){
            swap(u,v);
        }
        v=blockParent[v];
    }

}


int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        Tree[u].push_back(v);
    }

    parent[1]=-1;
    
    dfs1(1,0,0);
    bs=(int) sqrt(height);
    blockParent.resize(bs+1);
    dfs2(1,0);

    int q;
    while(q--){
        int u,v;
        cin>>u>>v;
       cout<<lca(u,v)<<endl;
    }


    return 0;
}