#include "fib.h"

int fibonacci(int n) {
  if (n <= 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int dynamicfib(int n) {
  int f[n+1];
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return f[n];
}
