import java.util.Scanner;
import java.util.Vector;

public class SmallestDifference {
    public static void main(String[] args) {
        // Create a Vector to store integers
        Vector<Integer> numbers = new Vector<>();

        // Read numbers from the user until zero is entered
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter integers (enter 0 to finish):");

        int input;
        do {
            input = scanner.nextInt();
            if (input != 0) {
                numbers.add(input);
            }
        } while (input != 0);

        // Find and display the two numbers with the smallest difference
        findSmallestDifference(numbers);
        scanner.close();
    }

    private static void findSmallestDifference(Vector<Integer> numbers) {
        if (numbers.size() < 2) {
            System.out.println("Insufficient numbers to find a difference.");
            return;
        }

        int smallestDifference = Integer.MAX_VALUE;
        int firstNumber = 0;
        int secondNumber = 0;

        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                int difference = Math.abs(numbers.get(i) - numbers.get(j));
                if (difference < smallestDifference) {
                    smallestDifference = difference;
                    firstNumber = numbers.get(i);
                    secondNumber = numbers.get(j);
                }
            }
        }

        System.out.println("Smallest difference: " + smallestDifference +
                " (between " + firstNumber + " and " + secondNumber + ")");
    }
}
