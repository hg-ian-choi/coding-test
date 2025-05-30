import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class 개인정보수집유효기간 {
  public int[] mySolution(String today, String[] terms, String[] privacies) {
    List<Integer> answer = new ArrayList<Integer>();
    try {
      Map<String, Integer> termsMap = new HashMap<>();
      for (String term : terms) {
        String[] termArray = term.split(" ");
        termsMap.put(termArray[0], Integer.parseInt(termArray[1]));
      }

      SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
      for (int i = 0; i < privacies.length; i++) {
        String[] privacyArray = privacies[i].split(" ");
        Date todayDate = simpleDateFormat.parse(today);
        Date date = simpleDateFormat.parse(privacyArray[0]);
        Calendar cal = Calendar.getInstance();
        cal.setTime(date);
        cal.add(Calendar.MONTH, termsMap.get(privacyArray[1]));
        Date newDate = cal.getTime();
        if (todayDate.compareTo(newDate) >= 0) {
          answer.add(i + 1);
        }
      }
    } catch (Exception error_) {
      System.out.println(error_);
    }
    return answer.stream().mapToInt(integer -> integer).toArray();
  }


  // Solution
  public int[] solution(String today, String[] terms, String[] privacies) {
    List<Integer> answer = new ArrayList<>();
    Map<String, Integer> termMap = new HashMap<>();
    int date = getDate(today);

    for (String s : terms) {
      String[] term = s.split(" ");

      termMap.put(term[0], Integer.parseInt(term[1]));
    }
    for (int i = 0; i < privacies.length; i++) {
      String[] privacy = privacies[i].split(" ");

      if (getDate(privacy[0]) + (termMap.get(privacy[1]) * 28) <= date) {
        answer.add(i + 1);
      }
    }
    return answer.stream().mapToInt(integer -> integer).toArray();
  }

  private int getDate(String today) {
    String[] date = today.split("\\.");
    int year = Integer.parseInt(date[0]);
    int month = Integer.parseInt(date[1]);
    int day = Integer.parseInt(date[2]);
    return (year * 12 * 28) + (month * 28) + day;
  }
}
