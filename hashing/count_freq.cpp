#include <bits/stdc++.h>
using namespace std;
int freq[26];

int hash_func(char c){
    return c-'a';
}

int main(){
    

    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
    string s="ababcd";
    int n=s.length();

    for(int i=0;i<n;i++){
        int index=hash_func(s[i]);
        freq[index]++;
    }

    for(int i=0;i<26;i++){
        cout<<(char)(i+'a')<<" "<<freq[i]<<endl;
    }

}