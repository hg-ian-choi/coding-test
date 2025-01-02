#include <math.h>

int arrangeCoins(int n) {
  int level = 0;

  while (n - level > 0) {
    level++;
    n -= level;
  }

  return level;
}

// Best Solution 1: Iterative Approach
int bestSolution1(int n) {
  // which row we are on
  int i = 1;

  // checking to see if we have used all our coins
  while (n > 0) {
    // increasing our row
    i++;

    // adding coins to our row
    n = n - i;
  }

  // we return our current row minus one because the last row is our completed row
  return i - 1;
}

// Best Solution 2: Binary Search Approach
int bestSolution2(int n) {
  // we use "long" because we may get an integer overflow
  long left = 0;
  long right = n;

  while (left <= right) {
    long pivot = left + (right - left) / 2;
    long coinsUsed = pivot * (pivot + 1) / 2;
    if (coinsUsed == n) {
      return (int)pivot;
    }
    if (n < coinsUsed) {
      right = pivot - 1;
    } else {
      left = pivot + 1;
    }
  }

  // cast as an "int" because it was initiliazed as a "long"
  return (int)right;
}

// Best Solution 3: Math Approach (using algebra)
int bestSolution3(int n) {
  // cast "n" to "long" to avoid integer overflow
  return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
}

// Best Solution 4: Math Approach (using Quadratic Formula)
int bestSolution4(int n) {
  // cast "n" to "long" to avoid integer overflow
  return (int)(-1 + (sqrt(1 + 8 * (long)n))) / 2;
}