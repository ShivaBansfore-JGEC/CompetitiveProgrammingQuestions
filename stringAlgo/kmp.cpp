#include <bits/stdc++.h>
using namespace std;
const int p=31;
const int m =1e9 + 9;
typedef long long ll;
vector<int> lpsArray(string s){
    int n=s.size();
    vector<int>lps(n);
    int index=0;
    int i =1;
    while ((i<n))
    {
        if(s[i]==s[index]){
            lps[i]=index+1;
            i++;
            index++;
        }else
        {
            if (index!=0)
            index=lps[index-1];
            else{
                lps[i]=index;
                i++;
            }
        }
        
    }
    return lps;    

}

void kmp(string s,string t){
    int n=t.size();
    vector<int>lps(n);
    lps=lpsArray(t);
    int i=0,j=0;
    while (i<s.size())
    {
        if (s[i]==t[j]){
            i++;
            j++;
        }else
        {
          if(j!=0) j=lps[j-1];
          else 
          i++;
        }

        if (j==n){

            cout<<i-n<<endl;
            j=lps[j-1];
        }
        
    }
    

}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    string s,t;
    cin>>s;
    cin>>t;
    kmp(s,t);

    return 0;
}