#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=19;

string hashTable[21];
int hashsize=21;

ll hashFunc(string s){
    int n=s.size();
    ll hashVal=0;
    for(int i=0;i<n;i++){
        hashVal+=((ll)((s[i]-'a')*(pow(p,i))));
    }
    return hashVal%hashsize;
}
void insert(string s){

    //compute the index using hash fuction 
    int index=hashFunc(s);

    // search for unused slot and if not found then roll back 
    while (hashTable[index]!="")
    {
        index=(index+1)%hashsize;
    }

    hashTable[index]=s;
}


void search(string s){
    //compute the hash value 
    int index=hashFunc(s);
    
     //Search for an unused slot and if the index will exceed the hashTableSize then roll back

     while(hashTable[index]!=s and hashTable[index]!=""){
         index=(index+1)%hashsize;
     }
     if(hashTable[index]==s) cout<<hashTable[index]<<" is "<<"found"<<endl;
     else cout<<"not found"<<endl;
}


int main(){

    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif

        string s[]={"shiva","sunny","pankaj"};
        for(string v:s){
            insert(v);
        }
        search("sun");


return 0;
}