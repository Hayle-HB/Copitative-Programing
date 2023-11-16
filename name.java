import java.util.Vector;
import java.util.Scanner;

public class name {

  public static Vector<String> Max_Min_Average(Vector<Integer> Max) {
    Vector<String> Answer = new Vector<>();
    int size = Max.size();
    int max = Max.get(0);
    int min = Max.get(0);
    double Average = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
      if (Max.get(i) > max) {
        max = Max.get(i);
      }

      else if (Max.get(i) < max) {
        min = Max.get(i);
      }
      sum += Max.get(i);
    }
    Average = sum / (double) size;

    Answer.add("Average= " + Average);
    Answer.add("Maximun= " + max);
    Answer.add("Minimun= " + min);

    return Answer;
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    Vector<Integer> integers = new Vector<>();
    while (true) {
      System.out.print("Enter Posetive Number or -ve to Stop: ");
      int num = scan.nextInt();

      if (num < 0) {
        break;
      } else {
        integers.add(num);
      }
    }

    Vector<String> Answer = new Vector<>();
    Answer = Max_Min_Average(integers);

    System.out.println("*********************\n" + Answer);

    scan.close();
  }
}