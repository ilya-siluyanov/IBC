#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a == 0)return b;
    if (b == 0)return a;
    if (a >= b)return gcd(b, a % b);
    return gcd(a, b % a);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}
