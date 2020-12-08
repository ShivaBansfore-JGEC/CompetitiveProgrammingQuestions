#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=31;
string hashTable[100001];
int hash_size=100001;

ll hash_func(string roll){
    int n=roll.size();
    ll hashval =0;
    for(int i=0;i<n;i++){
        hashval+=((roll[i]-'a')*(ll)pow(p,i))%hash_size;
    }
    return abs(hashval)%hash_size;
}


void insert(string roll,string name){
    int index=hash_func(roll);
    while(hashTable[index]!=""){
        index=(index+1)%hash_size;
    }
    hashTable[index]=name;

}

void search(string roll){
    int index=hash_func(roll);
    cout<< hashTable[index]<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
    int n;
    cin>>n;

    while (n--){
        string roll,name;
        cin>>roll>>name;
        insert(roll,name);
    }
    int q;
    cin>>q;
    while(q--){
        string roll;
        cin>>roll;
        search(roll);
    }
    return 0;
}

/*


 string r;
        cin>>r;
        search(r);



*/