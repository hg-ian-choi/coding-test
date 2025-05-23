class SingleNumber {
  int singleNumber(List<int> nums) {
    int result = 0;
    for (int num in nums) {
      result ^= num;
    }
    return result;
  }


  // Solution
  int solution(List<int> nums) {
    int result = 0;
    for (int num in nums) {
      result = result ^ num;
    }
    return result;
  }
}
