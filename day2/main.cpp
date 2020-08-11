#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
#define P pair<double,double>
#define pb push_back
typedef long long ll;
typedef long double ld;
#define maxN 1000
ld dist[maxN][maxN];
ld minDist = 10e18;
ll n;
vector<ll> path;

ld getDist(vector<ll> &v) {
    ld d = 0;
    d += dist[1][v[0]];
    for (ll i = 1; i <= v.size() - 1; i++) {
        ld x = dist[v[i - 1]][v[i]];
        d += x;
    }
    d += dist[v[v.size() - 1]][1];
    return d;
}

//not an algorithm
void permutations(vector<ll> &v, set<ll> &was) {
    if (v.size() == n - 1) {
        ll res = getDist(v);
        if (res < minDist) {
            path = vector<ll>();
            for (ll t:v)path.pb(t);
        }
        return;
    }
    for (ll i = 2; i <= n; i++) {
        if (!was.count(i)) {
            was.insert(i);
            v.pb(i);
            permutations(v, was);
            v.erase(v.end() - 1);
            was.erase(i);
        }
    }
}


int main() {
    cin >> n;
    vector<ll> v;
    for (ll i = 2; i <= n; i++) {
        v.pb(i);
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<ll> xw;
    set<ll> was;
    permutations(xw, was);
    cout << minDist;
    for (ll t:path)cout << t << " ";
}
