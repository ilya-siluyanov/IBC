#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    double b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    double c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
    vector<double> x = {a, b, c};
    sort(x.begin(), x.end());
    if (x[2] > x[1] + x[0]) {
        cout<<"doesn't exist";
    }else{
        cout<<"exist";
    }

}
