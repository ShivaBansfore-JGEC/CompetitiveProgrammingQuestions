#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int res=arr[0];
    for(int i=1;i<n;i++) res=res^arr[i];
    
    int temp=res;
    int i=0;
    while(temp>0){
        if(temp&1){
            break;
        }
        i++;
        temp=temp>>1;
    }
    int mask=1<<i;
    int first_no=0;
    for(int i=0;i<n;i++){
        if((mask&arr[i])!=0){
            first_no=first_no^arr[i];
        }
    }

    int second_no=res^first_no;
    if(first_no<second_no){
        cout<<first_no<<" "<<second_no<<endl;
    }else{
        cout<<second_no<<" "<<first_no<<endl;
    }
    

}

int main(){

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr,n);
    return 0;
}