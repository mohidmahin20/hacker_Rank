#include<bits/stdc++.h>
#define ll  long long
#define pb  push_back
#define fastread()   (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main(){
       fastread();
       int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       ll a,b;
       cin>>a>>b;
        ll p = a*b;
        int l = p % 100;
        cout << l<< endl;
    } 

    return 0;
}