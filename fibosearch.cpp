#include <bits/stdc++.h>
using namespace std;

int fibo(vector<int> &v, int k) {
    int fib1 = 0;  // (m-2)th Fibonacci number
    int fib2 = 1;  // (m-1)th Fibonacci number
    int fibm = fib1 + fib2;  // mth Fibonacci number

    int n = v.size();

    // Finding the smallest Fibonacci number >= n
    while (fibm < n) {
        fib1 = fib2;
        fib2 = fibm;
        fibm = fib1 + fib2;
    }

    int offset = -1;  // Marks the eliminated range from the front

    while (fibm > 1) {
        // Check valid index
        int i = min(offset + fib1, n - 1);

        if (v[i] < k) {
            fibm = fib2;
            fib2 = fib1;
            fib1 = fibm - fib2;
            offset = i;
        } else if (v[i] > k) {
            fibm = fib1;
            fib2 = fib2 - fib1;
            fib1 = fibm - fib2;
        } else {
            return i;  // Element found
        }
    }

    // Check the last element
    if (fib1 && v[offset + 1] == k) {
        return offset + 1;
    }

    return -1;  // Element not found
}

int main() {
    vector<int> v{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int key = 21;  // Search for 21
    int ans = fibo(v, key);
    if (ans != -1) {
        cout << "Index of " << key << " is " << ans << endl;
    } else {
        cout << "Number " << key << " is not present in the vector" << endl;
    }
    return 0;
}
