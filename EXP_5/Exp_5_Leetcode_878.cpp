#include <iostream>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9 + 7;
        long long l = 1, r = 1LL * n * min(a, b);
        long long lcm = (1LL * a * b) / gcd(a, b);

        while (l < r) {
            long long mid = (l + r) / 2;
            long long count = mid / a + mid / b - mid / lcm;

            if (count < n) l = mid + 1;
            else r = mid;
        }

        return l % mod;
    }
};