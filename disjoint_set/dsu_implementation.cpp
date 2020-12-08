#include<bits/stdc++.h>
using namespace std;
int parent[6];

int find(int a){
    while(parent[a]>0){
        a=parent[a];
    }
    return a;
}


void unin(int a,int b){
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
     for(int i=1;i<=n;i++){
        parent[i]=-1;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a!=b) unin(a,b);
    }

	long long int res = 1;
 
	for(int i=1;i<=n;i++)
	if(parent[i] < 0)
	res = (res * abs(parent[i])) % 1000000007;

 
	cout<<res;
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }
}