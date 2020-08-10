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

string digit(int d) {
    switch (d) {
        case 0:
            break;
        case 1:
            return "I";
            break;
        case 2:
            return "II";
            break;
        case 3:
            return "III";
            break;
        case 4:
            return "IV";
            break;
        case 5:
            return "V";
            break;
        case 6:
            return "VI";
            break;
        case 7:
            return "VII";
            break;
        case 8:
            return "VIII";
            break;
        case 9:
            return "IX";
            break;
    }
}


int main() {
    int x;
    cin >> x;
    //i - 1,v - 5,x - 10,l - 50,c - 100
    if (x == 100) {
        cout << "C" << endl;
        exit(0);
    }
    if (x <= 9) {
        cout << digit(x) << endl;
        exit(0);
    }
    int t = x / 10;
    string ans;
    switch (t) {
        case 1:
            ans += "X";
            break;
        case 2:
            ans += "XX";
            break;
        case 3:
            ans += "XXX";
            break;
        case 4:
            ans += "IL";
            break;
        case 5:
            ans += "L";
            break;
        case 6:
            ans += "LI";
            break;
        case 7:
            ans += "LII";
            break;
        case 8:
            ans += "LIII";
            break;
        case 9:
            ans += "IC";
            break;
    }
    ans += digit(x % 10);
    cout << ans;

}
