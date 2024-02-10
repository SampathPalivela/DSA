#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
#include <valarray>
#include <bits/stdc++.h>
using namespace std;




int countsteps(int n, int *arr) {
    if (n <= 1) {
        return 0;
    }
    if (arr[n] != -1) {
        return arr[n];
    }

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    x = countsteps(n - 1, arr);
    if (n % 2 == 0){
        y = countsteps(n / 2, arr);
    }
    if (n % 3 == 0) {
        z = countsteps(n / 3, arr);
    }
    int output = 1 + min(x, min(y, z));
    arr[n] = output;
    return output;
}

int countStepsToOne(int n) {
    int *arr = new int[n + 1];  
    for (int i = 0; i < n + 1; i++) {
        arr[i] = -1;
    }
    int result = countsteps(n, arr);
    delete[] arr;  
    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}