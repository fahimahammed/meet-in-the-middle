#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll X[2000005], Y[2000005];

void sumOfSubset(ll a[], ll x[], int n, int start)
{
    for( int i=0; i< (1<<n); i++){
        ll s = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                s += a[j+start];
            }
        }
        x[i] = s;
        //cout<<x[i]<<endl;
    }
}

ll findPossibleSum (ll a[], int n, ll S)
{
    //cout<<"X"<<endl;
    sumOfSubset(a, X, n/2, 0);
    //cout<<endl<<"Y"<<endl;
    sumOfSubset(a, Y, (n-n/2), n/2);

    int num_of_subset_X = 1<<n/2;
    int num_of_subset_Y = 1<<(n-n/2);

    ll max = 0;
    sort(Y, Y+num_of_subset_Y);

    for(int i=0; i<num_of_subset_X; i++){

        if(X[i] <= S){
            int p = lower_bound(Y, Y+num_of_subset_Y, S-X[i]) - Y;

            if( p == num_of_subset_Y || Y[p] != (S-X[i])){
                p--;
            }
            if((Y[p])+X[i] > max){
                max = Y[p]+X[i];
            }
        }
    }
    return max;
}

int main()
{
    ll a[] = {5, 3, 0, 7, 8, 9, 1};
    ll S = 2;

    int n = sizeof(a)/sizeof(a[0]);
    cout << "Maximum possible sum of subset is = "<<findPossibleSum(a, n, S)<<endl;
    return 0;
}
