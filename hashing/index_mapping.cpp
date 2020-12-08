#include <bits/stdc++.h>
using namespace std;
#define max 1000
bool max_a[max][2];


bool search(int s){
    if (s>=0){
        if (max_a[s][0]==1) return true ;
        else return false;
        
    }


    s=abs(s);
    if(max_a[s][1]==1) return true;
    else return false;
}

void insert(int x){
    if (x>=0){
        max_a[x][0]=1;
    }else
    {
        max_a[abs(x)][1]=1;
    }
    

}

int main(){

    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
    int arr[]={ -1, 9, -5, -8, -5, -2 };
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        insert(arr[i]);
    }

    if(search(-5)){
        cout<<"found";
    }else cout<<"not found";

        
}