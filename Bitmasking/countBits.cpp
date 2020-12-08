#include<bits/stdc++.h>
using namespace std;

// time- o(no of bits)
int counBits(int n){
    int count=0;
    while(n>0){
        count+=(n&1);
        n=n>>1;
    }

    return count;
}

//time - o( no of set bits)
int countBitsFast(int n){
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}

//extract ith bit

int getIthBit(int n,int i){
    return (n&(n<<i))!=0?1:0;
}

//set ith bit

void setIthBit(int &n,int i){
    int mask=1<<i;
    n=n|mask;
}

void clearIthBit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
}

int main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n,i;
    cin>>n>>i;

    cout<<counBits(n)<<endl;
    cout<<countBitsFast(n)<<endl;

    cout<<getIthBit(n,i)<<endl;

    setIthBit(n,i);
    cout<<n<<endl;

    clearIthBit(n,i);
    cout<<n<<endl;
    return 0;
}