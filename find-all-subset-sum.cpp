/*Find sum of subset.
Author: Fahim Ahammed Firoz
*/

#include <iostream>
using namespace std;
typedef long long int ll;

void sumOfSubset (ll a[], int n)
{
    for( int i=0; i< (1<<n); i++){

        ll s = 0;
        cout << "Subset "<<i<< " : { ";

        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                cout << a[j] << " ";
                s += a[j];
            }
        }
        cout <<"}"<<endl<<"Sum of Subset "<<i<<" = "<<s<<endl;
        cout<<endl;
    }
}

int main()
{
    ll a[] = {1, 2, 3};
    int n = sizeof(a)/ sizeof(a[0]);
    ll S = 10;

    sumOfSubset(a, n);
    return 0;
}
