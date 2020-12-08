#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=31;
int hashTable[100001]={-1};
int hashSIze=100001;

ll hashFunc(string s){
	int n=s.size();
    ll hashVal=0;
    for(int i=0;i<n;i++){
        hashVal+=((ll)((s[i]-'a')*(pow(p,i))));
    }
    return abs(hashVal)%hashSIze;
}
string insert(string s){
	int index=hashFunc(s);
	if (hashTable[index]!=-1){
		return s+ to_string(hashTable[index]);
	}else{
		while(hashTable[index]!=-1){
			index=(index+1)%hashSIze;
		}
		hashTable[index]++;
		return "ok";

	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		/*string s;
		cin>>s;
		cout<<insert(s);
		*/
		cout<<"hi";
	}
	return 0;
}