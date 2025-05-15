#include <iostream>
using namespace std;

long long evklid(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = evklid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long x, y;
    long long gcd = evklid(a, b, x, y);

    if (c % gcd != 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    x *= (c / gcd);
    y *= (c / gcd);

    long long k = x / (b / gcd);
    if (x < 0 && (x % (b / gcd) != 0)) {
        k--;
    }
    x -= k * (b / gcd);
    y += k * (a / gcd);

    if (x < 0) {
        x += (b / gcd);
        y -= (a / gcd);
    }

    cout << x << " " << y << endl;
    return 0;
}
