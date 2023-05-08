#include <iostream>
#include <cassert>


// Розрахунок довжини числа у системі числення b
template <typename T1>
T1 number_length(T1 n, T1 b) {
    int len = 0;
    while (n > 0) {
        n /= b;
        len++;
    }
    return len;
}

// Розрахунок k, такого що b^k > n
template <typename T1>
T1 get_k(T1 n, T1 b) {
    T1 k = 0;
    while (b > 1 && b <= n) {
        b *= b;
        k++;
    }
    return k;
}

// Обчислення результуючого множника для Монтгомері
template <typename T1>
T1 get_t(T1 n) {
    T1 t = 1;
    T1 two = 2;
    T1 k = number_length(n, two);
    for (int i = 0; i < k; i++) {
        t = (t * t) % n;
    }
    return t;
}

// Функція піднесення в степінь Монтгомері
template <typename T1>
T1 fpow(T1 a, T1 b, T1 n) {

    if(a == 0,b == 0){
        return 1;
    }
    T1 two = 2;
    T1 k = get_k(n, two);
    T1 r = 1;
    T1 t = get_t(n);
    a = (a * t) % n;

    while (b > 0) {
        if (b & 1) {
            r = (r * a) % n;
        }
        a = (a * a) % n;
        b >>= 1;
    }

    return (r * 1LL * t) % n;
}

int main() {
    int a = 125;
    int b = 16;
    int n = 21;

    std::cout << a << " pow " << b << " mod " << n << " = " << fpow(a, b, n) << std::endl;

    assert(fpow(0, 0, 1) == 1);
    assert(fpow(0, 1, 1) == 0);
    assert(fpow(1, 0, 1) == 1);
    assert(fpow(1, 1, 1) == 0);
    assert(fpow(3, 5, 7) == 5);
    assert(fpow(4, 13, 497) == 445);
    assert(fpow(7, 560, 561) == 1);
    assert(fpow(2LL, 1000000000LL, 10000007LL) == 6705727);


    return 0;
}