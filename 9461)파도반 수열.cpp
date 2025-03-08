#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;

long long dp(int n) {
    if (n < arr.size())
        return arr[n];

    for (int i = arr.size(); i <= n; i++)
        arr.push_back(arr[i - 3] + arr[i - 2]);
    return arr[n];
}

int main() {
    int tc, n;

    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);

    cin >> tc;

    for (int i = 0; i < tc; i++) {
        cin >> n;
        cout << dp(n) << '\n';
    }
}