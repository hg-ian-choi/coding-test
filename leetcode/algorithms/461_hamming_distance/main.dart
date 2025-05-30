class HammingDistance {
  int hammingDistance(int x, int y) {
    int cnt = 0, n = x ^ y;
    while (n > 0) {
      cnt += n & 1;
      n >>= 1;
    }
    return cnt;
  }


  // Solution
  // Solution 1
  int solution1(int x, int y) {
    int result = 0;
    int xor = x ^ y;
    while (xor > 0) {
      final int remainder = xor % 2;
      result += remainder;
      xor ~/= 2;
    }
    return result;
  }

  // Solution 1
  int solution2(int x, int y) {
    return (x ^ y).toRadixString(2).replaceAll('0', '').length;
  }
}
