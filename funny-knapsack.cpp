#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sumOfSubset(ll a[], int n, ll S)
{
    ll count = 0;
    for(int i=0; i< (1<<n); i++){

        ll s = 0;
        for(int j = 0; j<n; j++){
            if(i & (1<<j)){
                s += a[j];
            }
        }
        if(s <= S){
            count ++;
        }
    }
    return count;
}


int main()
{
    ll a[2000], n, S, t, i, id=1;
    cin>>t;
    while(t--){
        cin>>n>>S;
        for(i=0; i<n; i++){
            cin>>a[i];
        }
        cout<<"Case "<<id++ <<": "<<sumOfSubset(a, n, S)<<endl;
    }

    return 0;
}
