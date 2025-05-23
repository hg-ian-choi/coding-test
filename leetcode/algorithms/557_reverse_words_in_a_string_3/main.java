class ReverseWordsInAStringIII {
  public String reverseWords(String s) {
    String[] sArray = s.split(" ");
    for (int i = 0; i < sArray.length; i++) {
      sArray[i] = new StringBuffer(sArray[i]).reverse().toString();
    }
    return String.join(" ", sArray);
  }


  // Solution
  public String solution(String s) {
    char[] ca = s.toCharArray();
    for (int i = 0; i < ca.length; i++) {
      if (ca[i] != ' ') { // when i is a non-space
        int j = i;
        while (j + 1 < ca.length && ca[j + 1] != ' ') {
          j++;
        } // move j to the end of the word
        reverse(ca, i, j);
        i = j;
      }
    }
    return new String(ca);
  }

  private void reverse(char[] ca, int i, int j) {
    for (; i < j; i++, j--) {
      char tmp = ca[i];
      ca[i] = ca[j];
      ca[j] = tmp;
    }
  }
}
