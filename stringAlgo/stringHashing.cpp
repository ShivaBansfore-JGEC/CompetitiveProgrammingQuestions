#include <bits/stdc++.h>
using namespace std;


long long computeHash(string s){
    int n=s.size();
    const int p=31;
    const int m =1e9+9;
    long long hashVal=0;
    long long pow=1;
    for(char c:s){
        hashVal=(hashVal+(c-'a'+1)*pow)%m;
        pow=(pow*p)%m;
    }
    return hashVal;
}

vector<vector<int>>  findDuplicates(string s){
    int n=s.size();
    vector<pair<long long,int>> hash_val(n);
    for(int i=0;i<n;i++){
        hash_val[i]={computeHash(s),i};
    }
    vector<vector<int>> group;
    for(int i=0;i<n;i++){
        if(i==0 || hash_val[i].first!=hash_val[i-1].first)
            group.emplace_back();
        group.back().push_back(hash_val[i].second);
    }

    return group;

}

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int n;
    string s,h;
    cin>>n;
    cin>>s;
    cin>>h;
    cout<<computeHash(s);



 }