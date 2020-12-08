#include<bits/stdc++.h>
using namespace std;

void filterChar(char *a,int n){
    int i=0;
    while(n>0){
        (n&1)?cout<<a[i]:cout<<"";
        i++;
        n=n>>1;
    }
    cout<<endl;
}


//generatae all subsets
void generate(char *a){

    int n=strlen(a);
    int range=(1<<n)-1;
    for(int i=0;i<range;i++){
        filterChar(a,i);
    }
}
int main(){

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    char a[100];
    cin>>a;
    generate(a);
    return 0;
}