#include<bits/stdc++.h>
using namespace std;
vector<int> parent(1000);
vector<int> Rank(1000);

int find(int a){
    if(parent[a]<0)
    return a;
    else
    {
        int x=find(parent[a]);
        parent[a]=x;
        return x;
    }

}

void merge(int a,int b){
    if(a==b)
        return;
    if(Rank[a]>Rank[b]){
        //a would be the parent
        parent[b]=a;
        Rank[a]+=Rank[b];
    }else{
        // b would be the parent
        parent[a]=b;
        Rank[b]+=Rank[a];
    }
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

    for(int i=1;i<=n;i++){
        parent[i]=-1,Rank[i]=1;
    }

    while(m--){

        int a,b;
        cin>>a>>b;
        a=find(a);
        b=find(b);
        merge(a,b);
    }

    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }


    return 0;
}

