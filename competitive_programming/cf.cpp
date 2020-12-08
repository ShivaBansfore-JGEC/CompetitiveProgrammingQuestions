#include <bits/stdc++.h>
using namespace std;


int t,n,a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    cin>>t;
    while(t--){
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k=0;
        while(k<n && a[k]==1)
        k++;
        
        if(k==n){
            if(k%2==0) cout<<"Second"<<endl;
            else cout<<"First"<<endl;
        }else{

            if(k%2==0) cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }
    }

    return 0;
}



/*
string a,b;
int t,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        vector<int> p;

        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(i>0) p.push_back(i+1);
                p.push_back(1);
                if(i>0) p.push_back(i+1);
            }
        }
        cout<<p.size()<<" ";
        for(int x:p){
            cout<<x<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
*/


/*
int sumof_digit(int n){
    int sum=0;
    while (n!=0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
    
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int chef=0;
        int morty=0;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            int cf=sumof_digit(a);
            int mnt=sumof_digit(b);
            if(cf>mnt){
                chef+=1;
            }else if(mnt>cf){
                morty+=1;
            }
        }
        if(chef>morty){
            cout<<0<<" "<<chef<<endl;

        }else if(morty>chef){
            cout<<1<<" "<<morty<<endl;
        }else{
            cout<<2<<" "<<chef<<endl;
        }
        
    }

    return 0;
}

*/

/*
int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int t;
    cin>>t;
    
    while(t--){
        int n;
        int sum=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                sum+=((arr[i]-arr[i+1])-1);
            }else if(arr[i+1]>arr[i]){
                sum+=((arr[i+1]-arr[i])-1);
            }else
            {
                sum+=0;
            }
            
        }

        cout<<sum<<endl;
    }
return 0 ;
}
*/