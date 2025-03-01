#include <iostream>
using namespace std;

int evklid (int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = evklid (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    int gcd = evklid (a, b, x, y);

    if (c % gcd != 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    x *= (c / gcd);
    y *= (c / gcd);

    int k = (x * gcd) / b;
    x -= k * (b / gcd);
    y += k * (a / gcd);

    if (x < 0) {
        x += (b / gcd);
        y -= (a / gcd);
    }

    cout << x << " " << y << endl;
    return 0;
}