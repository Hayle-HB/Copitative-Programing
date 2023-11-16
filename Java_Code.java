import java.util.Vector;
import java.util.Scanner;

public class Java_Code {

  public static Vector<String> Reverse_Word(Vector<String> Words) {
    Vector<String> Reverse = new Vector<>();
      
      for(int i =Words.size() -1; i >=0; i-- ){
        Reverse.add(Words.get(i));
      }

    return Reverse;
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    Vector<String> Words = new Vector<>();
    String terminateWord = "";

    while(true){

      System.out.println("Enter Word or \"done\" to Stop: ");
      terminateWord = scan.nextLine();
      if(terminateWord.toLowerCase().equals("done")){
        break;
      }

      else {
        Words.add(terminateWord);
      }
    }
  

    
    System.out.println("*********************\n" + Reverse_Word(Words));

    scan.close();
  }
}