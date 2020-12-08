#include<bits/stdc++.h>
using namespace std;

int parent[100000];

int find(int a){
    while(1){
        if(parent[a]==a){
            return a;
        }else{
            a=parent[a];
        }
    }
}

void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    else parent[a]=b;
}

int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    while(k--){
        int a,b;
        cin>>a>>b;
        merge(a,b);

    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(parent[i]==i) res++;
    }
    cout<<res<<endl;

    return 0;
}