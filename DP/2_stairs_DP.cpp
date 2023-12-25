#include<bits/stdc++.h>
using namespace std;

const long MOD = 1000000007;

long ways(long n, long* arr) {
    if (n == 0) {
        return 1;
    }
    if (arr[n] != -1) {
        return arr[n];
    }
    long x = 0, y = 0, z = 0;
    if (n - 1 >= 0) {
        x = ways(n - 1, arr);
        x %= MOD;
    }
    if (n - 2 >= 0) {
        y = ways(n - 2, arr);
        y %= MOD;
    }
    if (n - 3 >= 0) {
        z = ways(n - 3, arr);
        z %= MOD;
    }
    long output = (x + y + z)%MOD;
    arr[n] = output;
 
    return output;
}

long countways(long n) {
    long* arr = new long[n + 1];
    for (long i = 0; i < n + 1; i++) {
        arr[i] = -1;
    }
    long ans = ways(n, arr);
    delete [] arr;
    return ans ;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        long n;
        cin >> n;
        cout << countways(n) << endl;
        t--;
    }
    return 0;
}
