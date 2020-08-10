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
long long T = 1000000;

bool cmpy(P &a, P &b) {
    return a.second < b.second;
}

double len(P a) {
    return sqrt(pow(a.first, 2) + pow(a.second, 2));
}

double len(P a, P b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double cosMult(P a) {
    P b = {T, 0};
    double first = a.first * b.first + a.second * b.second;
    double second = len(a) * len(b);
    return first / second;
}


double sinMult(P a) {
    P b = {T, 0};

    double first = b.first * a.second - b.second * a.first;
    double second = len(a) * len(b);
    return first / second;
}

double angle(double cos, double sin) {
    double angle = acos(cos);
    if (sin < 0) {
        angle = 2 * M_PI - angle;
    }
    return angle;
}

struct node {
    double x;
    double y;
    double angle;

    node(double x, double y, double angle) : x(x), y(y), angle(angle) {}
};

bool cmpAngle(node a, node b) {
    return a.angle < b.angle;
}


double roun(double angle) {
    double ang = angle * T;
    double an = round(ang);
    an = an / (1.0 * T);
    return an;
}

P direct(P a, P b) {
    double ax = (a.second - b.second);
    double bx = (a.first - b.first);
    double k = (ax) / (bx);
    double bc = a.second - k * a.first;
    if (isnan(bc) || isnan(k) || isinf(k) || isinf(-k)) {
        k = INFINITY;
        bc = a.first;
    }
    return {k, bc};
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;
    vector<P > dots;
    dots.pb({x1, y1});
    dots.pb({x2, y2});
    dots.pb({x3, y3});
    dots.pb({x4, y4});
    set<P > dirs;
    set<P > was;
    for (int i = 0; i < 4; i++) {
        vector<node> v;
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;

            P dot = {dots[j].first - dots[i].first, dots[j].second - dots[i].second};
            double cos = roun(cosMult(dot));
            double sin = roun(sinMult(dot));
            double angl = angle(cos, sin);
            double deg = 1.0 * 180 / M_PI * angl;
            v.push_back(node(dots[j].first, dots[j].second, angl));
            was.insert({min(i, j), max(i, j)});
        }
        sort(v.begin(), v.end(), cmpAngle);

        dirs.insert(direct({v[0].x, v[0].y}, dots[i]));
        dirs.insert(direct({v[2].x, v[2].y}, dots[i]));
    }
    map<double, int> cnt;
    for (P d:dirs) {
        cnt[d.first]++;
    }
    set<P > rdirs;
    for (P x:cnt) {
        if (x.second > 1) {
            for (P d:dirs) {
                if (d.first == x.first)
                    rdirs.insert(d);
            }
        }
    }
    dirs = rdirs;
    for (P x:dirs) {
        if (x.first == -0) {
            dirs.erase(x);
            x.first = 0;
            dirs.insert(x);
        }
    }
    cnt = map<double, int>();
    vector<P > pr;
    for (P x:dirs) {
        cnt[x.first]++;
        pr.pb(x);
    }
    vector<P > first;
    vector<P > second;
    double f = cnt.begin()->first;
    double s = cnt.rbegin()->first;
    for (P y:pr) {
        if (y.first == f) {
            first.pb(y);
        }
    }
    for (P y:pr) {
        if (y.first == s) {
            second.pb(y);
        }
    }
    if (first[0].second > first[1].second)swap(first[0], first[1]);
    if (second[0].second > second[1].second)swap(second[0], second[1]);

    int ok = 0;
    bool one = first[0].first * x5 + first[0].second <= y5;
    if (isinf(first[0].first)) {
        one = false;
        one = first[0].second <= x5;
    }
    bool two = first[1].first * x5 + first[1].second >= y5;
    if (isinf(first[1].first)) {
        two = false;
        two = first[1].second >= x5;
    }
    bool three = second[0].first * x5 + second[0].second <= y5;
    if (isinf(second[0].first)) {
        three = false;
        three = second[0].second <= x5;
    }
    bool four = second[1].first * x5 + second[1].second >= y5;
    if (isinf(second[1].first)) {
        four = false;
        four = second[1].second >= x5;
    }
    if (one) {
        if (two) {
            if (three) {
                if (four) {
                    ok = 1;
                }
            }
        }
    }
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
