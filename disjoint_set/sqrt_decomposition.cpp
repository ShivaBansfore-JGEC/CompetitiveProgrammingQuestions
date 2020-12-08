#include<bits/stdc++.h>
using namespace std;

vector<int> arr(11);
vector<int> F(3);
int len=(int) sqrt(11);

int getMIn(int l,int r){
    
    int lb=l/len;
    int rb=r/len;
    int mn=INT_MAX;

    if(lb==rb){
        for(int i=l;i<=r;i++){
            mn=min(mn,arr[i]);
        }

    }else{
        for(int i=l;i<len*(lb+1);i++){
            mn=min(mn,arr[i]);
        }

        //traversing in the block 

        for(int i=lb+1;i<=rb;i++){
            mn=min(mn,F[i]);
        }

        //travering in right block 
        for(int i=len*rb;i<=r;i++){
            mn=min(mn,arr[i]);
        }

    }
    return mn;

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
    for(int i=0;i<=n;i++) cin>>arr[i];

    //preprocessing
    for(int i=0;i<=F.size();i++){
        F[i]=INT_MAX;
    }
    
    for(int i=0;i<=n;i++){
        cout<<F[i/len]<<" "<<arr[i]<<endl;
        F[i/len]=min(F[i/len],arr[i]);
    }

    for(int i=0;i<=F.size();i++){
        cout<<F[i]<<" ";
    }

    cout<<endl;
    cout<<"min of l to r :"<<getMIn(8,8);

    return 0;
}