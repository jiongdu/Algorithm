#include <iostream>

using namespace std;

int main() {
    long long int n, sum = 0;
    cin >> n;
    int elem;
    for (int i = 0; i < n-1;i++) {
        cin >> elem;
        sum += elem;
    }
    cout << n * (n + 1) / 2 - sum;
    return 0;
}