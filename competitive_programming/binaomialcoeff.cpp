#include <bits/stdc++.h>
using namespace std;
int gcdExtended(int a,int b,int *x,int *y){
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1; // To store results of recursive call  
    int gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


    int a,b,n,k;
    cin>>a>>b>>n>>k;
    int x,y;
    cout<<gcdExtended(a,b,&x,&y)<<endl;
    cout<<x<<" "<<y;
    return 0;
}