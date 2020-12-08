#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int t; 
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s+="$";
        int n;
        n=s.size();

        vector<int> p(n),c(n);
        {
            // when k==0 
            vector<pair<char,int>> a(n);
            for(int i =0;i<n;i++){
                a[i]={s[i],i};
            }
            sort(a.begin(),a.end());

            for(int i =0;i<n;i++){
                p[i]=a[i].second;
            }
            /*
            //printing p 
            for(int i =0;i<n;i++){
                cout<<p[i]<<" ";
            }
            */
            //#####################

            c[p[0]]=0;
            for(int i=1;i<n;i++){
                if(a[i].first==a[i-1].first){
                    c[p[i]]=c[p[i-1]];
                }else{
                    c[p[i]]=c[p[i-1]]+1;
                }
            }
            /*
            //printing wquivalence class c 
               for(int i =0;i<n;i++){
                cout<<c[i]<<" ";
            }
            */

        }

        int k=0;
        while ((1<<k)<n){
            vector<pair<pair<int,int>,int>> a(n);
            for(int i=0;i<n;i++){
                a[i]={{c[i],c[(i+(1<<k)%n)]},i};
            }
            //printing a 
            /*
            cout<<"print a"<<endl;
              for(int i=0;i<n;i++){
                  cout<<a[i].first.first<<" "<<a[i].first.second<<" "<<a[i].second<<endl;
            }
            */

            sort(a.begin(),a.end());


            for(int i=0;i<n;i++) p[i]=a[i].second;

            c[p[0]]=0;
            for(int i=1;i<n;i++){
                if(a[i].first==a[i-1].first){
                    c[p[i]]=c[p[i-1]];
                }else{
                    c[p[i]]=c[p[i-1]]+1;
                }
            }

            k++;

        }

        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }

    }




}