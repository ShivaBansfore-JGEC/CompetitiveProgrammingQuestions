#include <bits/stdc++.h>
using namespace std;
const int p=31;
const int m =1e9 + 9;
typedef long long ll;
ll power(ll a,ll n){
    ll res=1;
    while(n!=0){
        if(n%2!=0){
            res=(res*a);
            n--;
        }
        a=(a*a);
        n/=2;
    }
    return res ;
}
ll computeHash(string s ,int n){
    ll hashVal=0;
    for(int i=0;i<n;i++){
        hashVal+=((ll)((s[i]-'a')*(pow(p,i))));
    }
    return hashVal;
}

ll recalculateHash(string s,int oldid,int newid,ll oldhash,int patlen){
    ll newHash=oldhash-(s[oldid]-'a');
    newHash/=p;
    newHash+= ((s[newid]-'a')*power(p,patlen-1));
    return newHash;
}

bool checkEqual(string s1,string s2,int strt1,int end1,int strt2,int end2){
    if (end1-strt1!=end2-strt2) return false;

    while (strt1<=end1 and strt2<=end2)
    {
        if (s1[strt1]!=s2[strt2]) return false;
        strt1++;
        strt2++;
    }
    return true;

}

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

    int n;
    string s,pat;
    cin>>n;
    cin>>pat;
    cin>>s;
    if(pat.size()>s.size()){
        cout<<" ";
    }else{
        ll pathash=computeHash(pat,n);
        ll str_hash=computeHash(s,n);
        for(int i =0;i<s.size()-n;i++){
            if (str_hash==pathash and checkEqual(s,pat,i,i+n-1,0,n-1)){
                cout<<i<<endl;
                str_hash=recalculateHash(s,i,i+n,str_hash,n);
            }else
            {
                str_hash=recalculateHash(s,i,i+n,str_hash,n);
            }
        }
    }
  

}