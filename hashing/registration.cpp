#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=31;
int hashTable[100001];

int hashSIze=100001;

ll hashFunc(string s){
	int n=s.size();
    ll hashVal=0;
    for(int i=0;i<n;i++){
        hashVal+=((ll)((s[i]-'a'+1)*(pow(p,i))));
    }
    return abs(hashVal)%hashSIze;
}
void insert(string s){
	int index=hashFunc(s);
    //cout<<index<<endl;
    //cout<<hashTable[10]<<endl;
    //cout<<s<<" "<<hashTable[index];
	if (hashTable[index]!=0){
		cout<<(s+ to_string(hashTable[index]))<<endl;
        hashTable[index]++;
        return;

	}else{
        int h=1;
		while(hashTable[index]!=0){
			index=(index+h*h)%hashSIze;
            h++;
		}
		hashTable[index]++;
		cout<<"OK"<<endl;
        return;

	}
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	 #endif
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		insert(s);
	}
	return 0;
}