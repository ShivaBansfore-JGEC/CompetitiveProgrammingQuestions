#include<bits/stdc++.h>
using namespace std;
vector<int>parent(1000);


int find(int a){
    while(parent[a]>0){
        a=parent[a];
    }
    return a;
}

int find_rec(int a){
    if(parent[a]<0)
    return a;
    else{
        int x=find(parent[a]);
        parent[a]=x;
        return x;
    }
}


void union_fuc(int a,int b){
    parent[a]=min(parent[a],parent[b]);
    parent[b]=a;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n,m,x,y,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=-i;
    }

    while(m--){
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a!=b) union_fuc(a,b);


    }
    int q;
    cin>>q;
    while(q--){
        cin>>a>>b;
        x=a,y=b;
        a=find(x);
        b=find(y);

        if(a==b){
            cout<<"TIE"<<endl;
        }else{
            if(parent[a]<parent[b]) cout<<x<<endl;
            else cout<<y<<endl;
        }
        
               
    }

    return 0;
}