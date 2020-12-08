#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p1=31;
const int p2=53;

string hashTable[21];
int hash_size=21;

ll hashfunc1(string s){
    int n=s.size();
    ll hashval=0;
    for(int i=0;i<n;i++){
        hashval=hashval+((s[i]-'a'+1)*pow(p1,i));
    }
    return hashval%hash_size;
}

ll hashfunc2(string s){
    int n=s.size();
    ll hashval=0;
    for(int i=0;i<n;i++){
        hashval=hashval+((s[i]-'a'+1)*pow(p2,i));
    }
    return hashval%hash_size;
}


void insert(string s ){

    int index=hashfunc1(s);
    int indexH=hashfunc2(s);
    while(hashTable[index]!=""){
        index=(index+indexH)%hash_size;
    }
    hashTable[index]=s;

}
void search(string s){
 int index=hashfunc1(s);
 int indexH=hashfunc2(s);
 while(hashTable[index]!=s and hashTable[index]!=""){
     index=(index+indexH)%hash_size;
 }

if(hashTable[index]==s) cout<<hashTable[index]<<" is found "<<endl;
else cout<<" not found ";

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