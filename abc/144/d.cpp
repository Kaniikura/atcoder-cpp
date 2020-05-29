#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
typedef long long ll;
using namespace std;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;

int a, b, x;

long double calc_vol(double degree, int a, int b)
{
    long double theta = (double)degree / 180 * PI;
    if (theta > PI / 2.0 - EPS)
    {
        return 0.0;
    }

    long double vol;
    if (a * tan(theta) <= b)
    {
        vol = a * a * b - a * a * a * tan(theta) / 2.0;
    }
    else
    {
        vol = b * b / tan(theta) * a / 2.0;
    }
    return vol;
}
void solve()
{
    long double max_err = 0.000001;
    long double vol = -1;
    long double low = 0;
    long double high = 90;
    long double mid;

    while (fabs(x - vol) > max_err)
    {
        mid = (low + high) / 2.;
        vol = calc_vol(mid, a, b);
        if (vol > x)
            low = mid;
        else
            high = mid;
    }
    cout << fixed << setprecision(10) << mid;
}

int main()
{
    cin >> a >> b >> x;

    solve();
}
