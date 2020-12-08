#include<bits/stdc++.h>
using namespace std;
int parent[1001];
int Rank[1001];

int find(int a)
{
    while(a!=parent[a]){
        a=parent[a];
    }
    return a;
}

void merge(int a,int b){
    a=find(a);
    b=find(b);

    if(a==b) return;
    if(Rank[a]>Rank[b]){
        parent[b]=a;
        Rank[a]+=Rank[b];
    }else{
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

    for(int i=1;i<=1000;i++){
        parent[i]=i,Rank[i]=1;
    }
    int n,x,y;
    cin>>n;
    cout<<"n:"<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        merge(x,y);
    }

    int nos=0;
    for(int i=1;i<=4;i++){
        if(find(i)==i)
            nos++;
    }

    cout<<nos<<endl;
    return 0;
}