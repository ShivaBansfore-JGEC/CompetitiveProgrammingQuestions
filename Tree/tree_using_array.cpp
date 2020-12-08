#include<bits/stdc++.h>
using namespace std;

int tree[10];
void init(){
    for(int i=0;i<10;i++){
        tree[i]=-1;
    }
}



void root(int val){
    if(tree[0]!=-1){
        cout<<"we already has a root"<<endl;
    }else
    {
        tree[0]=val;
    }
  
}

void leftchild(int key,int parent){
    if(tree[parent]==-1){
        cout<<"sorry we dont have this parent"<<endl;
    }else{
        tree[(2*parent)+1]=key;
    }
}

void rightchild(int key,int parent){
    if(tree[parent]==-1){
        cout<<"sorry we dont have this parent"<<endl;
    }else{
        tree[(2*parent)+2]=key;
    }
}

void printTree(){
    for(int i=0;i<10;i++){
        if(tree[i]!=-1) cout<<tree[i]<<" ";
        else cout<<"-";
    }
}




int main(){
    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
        init();

        root(1);
        leftchild(2,0);
        rightchild(3,0);
        leftchild(4,1);
        printTree();





}