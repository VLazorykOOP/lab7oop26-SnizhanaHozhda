#include <iostream>
#include <cstring>
#include "Tasks.h"

using std::cout;
using std::endl;
using std::ostream;

class TLong {
    long long hi, lo;
public:
    TLong() : hi(0), lo(0) {}
    TLong(long long h, long long l) : hi(h), lo(l) {}

    TLong& operator=(const TLong& s) {
        hi = s.hi;
        lo = s.lo;
        return *this;
    }

    bool operator>(const TLong& s) const {
        if (hi > s.hi) 
            return true;
        if (hi == s.hi && lo > s.lo) 
            return true;
        return false;
    }

    friend ostream& operator<<(ostream& os, const TLong& s);
};

ostream& operator<<(ostream& os, const TLong& s) {
    os << "H " << s.hi << ":L " << s.lo << " ";
    return os;
}

template <typename T>
T Max(T x, T y, T z, T u) {
    T t = (x > y) ? x : y;
    T r = (z > u) ? z : u;
    return (t > r) ? t : r;
}

template<>
const char* Max(const char* x, const char* y, const char* z, const char* u) {
    const char* t = (std::strcmp(x, y) > 0) ? x : y;
    const char* r = (std::strcmp(z, u) > 0) ? z : u;
    return (std::strcmp(t, r) > 0) ? t : r;
}

void runTask2() {
    cout << "=== Testing Function Templates ===\n" << endl;

    int a = 5, b = 4;
    int k = Max(a, 13, b, 5);
    cout << "Max int: " << k << " (Expected: 13)" << endl;

    double t = 3.5, q = 3.05;
    double r = Max(t, q, 3.45, 9.32);
    cout << "Max double: " << r << " (Expected: 9.32)" << endl;

    char s = 'a', n = 'f';
    char c = Max(s, 'r', n, 'z');
    cout << "Max char: " << c << " (Expected: z)" << endl;

    TLong l, i(100, 50), j(50, 100), e(75, 75), f(4, 200);
    l = Max(i, j, e, f);
    cout << "Max TLong: " << l << " (Expected: H 100:L 50)" << endl;

    const char* s1 = "text";
    const char* s2 = "txt";
    const char* s3 = "pltext";
    const char* s4 = "room";

    const char* s5 = Max(s1, s2, s3, s4);
    cout << "Max const char*: " << s5 << " (Expected: txt, because 'x' comes latest in the alphabet)" << endl;

}