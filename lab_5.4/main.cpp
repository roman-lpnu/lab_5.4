#include <iostream>
#include <cmath>
using namespace std;
double S0(const int k, const int N)
{
    double s = 0;
    for (int k = 1; k <= N; k++)
        s += 1 / pow(2 * k + 1, 2);
    return s;
}
double S1(const int k, const int N)
{
    if (k > N)
        return 0;
    else
        return (1 / pow(2 * k + 1, 2)) + S1(k + 1, N);
}
double S2(const int k, const int N)
{
    if (k < 1)
        return 0;
    else
        return (1 / pow(2 * k + 1, 2)) + S2(k - 1, N);
}
double S3(const int k, const int N, double t)
{
    t = t + 1 / pow(2 * k + 1, 2);
    if (k >= N)
        return t;
    else
        return  S3(k + 1, N, t);
}
double S4(const int k, const int N, double t)
{
    t = t + 1 / pow(2 * k + 1, 2);
    if (k <= 1)
        return t;
    else
        return S4(k - 1, N, t);
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << "(iter)        S0 = " << S0(1, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(1, N) << endl;
    cout << "(rec up --)   S2 = " << S2(N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(1, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, N, 0) << endl;
    return 0;
}