#include<bits/stdc++.h>
using namespace std;
int parent[200001];
int cnt=0;
vector<int> used(200001);
vector<int> ans(200001);

int find(int a){
    
    int cnt=1;
    int b=parent[a];
    while(b!=a){
        b=parent[b];
        cnt++;
    }
    
  return cnt;
    
   
}


int find(int a){
    int cnt=1;
    int b=parent[a];
    while(b!=a){
        b=parent[b];
        cnt++;
    }
    
  return cnt;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>parent[i];
        }
        for(int i=1;i<=n;i++){
    
            cout<<find(i)<<" ";
        }
        cout<<endl;
        
    }
}