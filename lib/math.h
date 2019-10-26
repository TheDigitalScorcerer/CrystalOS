#ifndef MATH_H
#define MATH_H 1

int abs(int x) {
    if (x < 0) {
        return 0 - x;
    }
    return x;
}

int pow(int m, int n) {
    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        ret *= m;
    }
    return ret;
}

#endif