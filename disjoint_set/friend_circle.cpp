#include<bits/stdc++.h>
using namespace std;
map<string,string> parent;
map<string,int> Rank;

void make_set(string k,string s){
    if(parent[k]=="")
        parent[k]=k;

    if(Rank[k]<2){
        Rank[k]=1;
    }
    if(parent[s]=="")
        parent[s]=s;

    if(Rank[s]<2){
        Rank[s]=1;
    }
}

string find(string key){
    if(parent[key]==key){
        return key;
    }else{
        return find(parent[key]);
    }
}

void merge(string a,string b){
    a=find(a);
    b=find(b);
    
    if(a==b) return;
    if(Rank[a]>Rank[b]){
        parent[b]=a;
        Rank[a]+=Rank[b];
    }else
    {
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

    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        make_set(s1,s2);
        merge(s1,s2);

        string par=find(s1);
        cout<<Rank[par]<<endl;

    }


    return 0;

}