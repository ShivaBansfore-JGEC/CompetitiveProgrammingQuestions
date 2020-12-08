#include<bits/stdc++.h>
using namespace std;
int parent[1000]; 


int find(int a){
    vector<int> v;
    while (parent[a]>0)
    {
        v.push_back(a);
        a=parent[a];
    }
    for(int i=0;i<v.size();i++){
        parent[v[i]]=a;
    }
    return a;
    
   
}

void merge(int a,int b){
    parent[a]+=parent[b];
    parent[b]=a;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    parent[i]=-1;
     while(m--){
        int a,b;
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a!=b) merge(a,b);
    }
    for(int i=1;i<=n;i++)
        cout<<parent[i]<<" ";
    
    return 0;
}