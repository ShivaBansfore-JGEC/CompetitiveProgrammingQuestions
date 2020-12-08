#include<bits/stdc++.h>
using namespace std;


int searchIn(int arr[],int s,int e,int key){
    //base case 
    if(s>e) return -1;

    int mid=(s+e)/2;

    if(arr[mid]==key){
        return mid;
    }

    if(arr[s]<=arr[mid]){
        if(key>=arr[s] && key<=arr[mid]){
            return searchIn(arr,s,mid-1,key);
        }else{
            return searchIn(arr,mid+1,e,key);
        }
    }

    if(key>= arr[mid] && key<=arr[e]){
        return searchIn(arr,mid+1,e,key);
    }
    return searchIn(arr,s,mid-1,key);

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int arr[]={5,6,7,1,2,3,4};
    int key;
    cin>>key;

    cout<<"Element found at:"<<searchIn(arr,0,6,key);

    return 0;
}