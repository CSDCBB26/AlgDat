//
//  main.c
//  laufzeit
//
//  Created by Juergen Falb on 26.03.21.
//

#include <stdio.h>

int f1(int n) {
    int result = 0;                         // 1
    
    for (int i = 0; i < n; i++) {           // 1 + (n+1) + n
        for (int j = 0; j < 2 * n; j++) {   // (1 + 2*(2*n + 1) + 2*n)          * n
            result += i * j;                // (2*n + 2*n)                      * n
        }
    }
    return result;                          // 1
}
// T(n) = 4 + 5*n + 10*n^2

int f2(int n) {
    int result = 0;                         // 1
    
    for (int i = n; i >= 1; i /= 2) {        // 1 + log2(n) + 1 + log2(n)
        for (int j = 0; j < 2 * n; j++) {   // (1 + 2*(2*n + 1) + 2*n)          * log2(n)
            result += i * j;                // (2*n + 2*n)                      * log2(n)
        }
    }
    return result;                          // 1
}
// 1 * 2 * 2 * 2 ... * 2 < n => 2^k < n => k < log2(n)
// 1, 2, 4, 8, 16, 32, 64 f. n = 100
// T(n) = 4 + 5*log2(n) + 10*n*log2(n)  => O(n*log(n))


long f3(int n) {
    if (n <= 1) return 1;       // 1
    return n * f3(n - 1);       // 1 + 1 + 1 + 1
}
// T(n) = 5*(n-1) + 2 = 5*n - 3 => O(n)

long f4(int n) {
    if (n <= 1) return 1;               // 1
    return f4(n - 1) + f4(n - 1);       // 6
}
// T(n) = 7*(2^n - 1) => O(2^n)

long f5(int n) {
    if (n <= 1) return 1;               // 1
    return 2 * f5(n - 1);               // 4
}
// T(n) = 4*(n - 1)  => O(n)

int main(int argc, const char * argv[]) {
    printf("start\n");
    long result = f5(33);
    printf("stop: %li\n", result);

    printf("start\n");
    result = f4(33);
    printf("stop: %li\n", result);

    return 0;
}
