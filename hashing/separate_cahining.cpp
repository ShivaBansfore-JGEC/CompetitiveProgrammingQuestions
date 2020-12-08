#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=19;


// ------- HASHING COLLISION RSOLUTION TECHNIQUE SEPARATE CHAINING ------- 





vector <string> hashTable[20];
    int hashTableSize=20;

ll hashFunc(string s ,int n){
    ll hashVal=0;
    for(int i=0;i<n;i++){
        hashVal+=((ll)((s[i]-'a')*(pow(p,i))));
    }
    return hashVal%20;
}


   void insert(string s)
    {
        vector<string> l;
                // Compute the index using Hash Function
        int index = hashFunc(s,s.size());
        cout<<index<<endl;
        // Insert the element in the linked list at the particular index
        hashTable[index].push_back(s);
    }

   void search(string s)
    {
        //Compute the index by using the hash function
        int index = hashFunc(s,s.size());
        //Search the linked list at that specific index
        for(int i = 0;i < hashTable[index].size();i++)
        {
            cout<<hashTable[index][i]<<endl;
            if(hashTable[index][i] == s)
            {
                cout << s << " is found!" << endl;
                return;
            }
        }
        cout << s << " is not found!" << endl;
    }


int main(){

    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif

        string s[]={"shiva","sunny","pankaj"};
        for(string v:s){
            insert(v);
        }
        search("sunny");

return 0;
}