#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=19;
string hashTable[21];
int hash_size=21;

ll hashfunc(string s){
    int n=s.size();
    ll hashval=0;
    for(int i=0;i<n;i++){
        hashval=hashval+((s[i]-'a'+1)*pow(p,i));
    }
    return hashval%hash_size;
}

void insert(string s){
    //compute index
    int index=hashfunc(s);
    int h=1;
    while (hashTable[index]!="")
    {
        index=(index+h*h)%hash_size;
        h+=1;
    }
    hashTable[index]=s;
    
}
void search(string s){
    int index=hashfunc(s);
    int h=1;
    while (hashTable[index]!=s and hashTable[index]!="")
    {
        index=(index+h*h)%hash_size;
        h++;
    }

    if(hashTable[index]==s){
        cout<<hashTable[index]<<" is "<<" found "<< endl;

    }else cout<<"not found";
    

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
        search("sunny");


return 0;
}