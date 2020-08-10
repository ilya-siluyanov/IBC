#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define P pair<double,double>
#define pb push_back
typedef long long ll;

bool cmpy(P &a, P &b) {
    return a.second < b.second;
}


int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;
    vector<P > dots;
    dots.pb({x1, y1});
    dots.pb({x2, y2});
    dots.pb({x3, y3});
    dots.pb({x4, y4});
    set<double> xs = {x1, x2, x3, x4};
    if (xs.size() == 2) {
        for (int i = 0; i < 4; i++)
            swap(dots[0].first, dots[0].second);
    }
    sort(dots.begin(), dots.end(), cmpy);
    for (int i = 0; i < 4; i += 2) {
        if (dots[i].first > dots[i + 1].first) {
            P t = dots[i];
            dots[i] = dots[i + 1];
            dots[i + 1] = t;
        }
    }
    P d1 = dots[0];
    P d2 = dots[2];
    P d3 = dots[1];
    P d4 = dots[3];
    x1 = d1.first;
    x2 = d2.first;
    x3 = d3.first;
    x4 = d4.first;
    y1 = d1.second;
    y2 = d2.second;
    y3 = d3.second;
    y4 = d4.second;
    //line is {k,b}, y = kx+b
    double k = (y2 - y1) / (x2 - x1);
    P firstLine = {k, y1 - k * x1};
    k = (y4 - y2) / (x4 - x2);
    P secondLine = {k, y2 - k * x2};
    k = (y4 - y3) / (x4 - x3);
    P thirdLine = {k, y3 - k * x3};
    k = (y3 - y1) / (x3 - x1);
    P fourthLine = {k, y1 - k * x1};
    if (firstLine.second < thirdLine.second) {
        swap(firstLine, thirdLine);
    }
    int ok = 0;
    if (firstLine.first * x5 + firstLine.second >= y5) {
        if (secondLine.first * x5 + secondLine.second >= y5) {
            if (thirdLine.first * x5 + thirdLine.second <= y5) {
                if (fourthLine.first * x5 + fourthLine.second <= y5) {
                    ok = 1;
                }
            }
        }
    }
    if (ok) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
