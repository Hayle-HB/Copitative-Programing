import java.util.Vector;
import java.util.Arrays;

public class Matrix_Multiplication {

    public static Vector<Vector<Integer>> MatrixMultiplication(Vector<Vector<Integer>> vector1,
            Vector<Vector<Integer>> vector2) {
        int rows1 = vector1.size();
        int cols1 = vector1.get(0).size();
        int cols2 = vector2.get(0).size();

        Vector<Vector<Integer>> result = new Vector<>();

        for (int i = 0; i < rows1; i++) {
            result.add(new Vector<>());
            for (int j = 0; j < cols2; j++) {
                int multiplication = 0;
                for (int k = 0; k < cols1; k++) {
                    multiplication += (vector1.get(i).get(k) * vector2.get(k).get(j));
                }
                result.get(i).add(multiplication);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Vector<Vector<Integer>> vector1 = new Vector<>();
        Vector<Vector<Integer>> vector2 = new Vector<>();

        // Populate vector1 with values
        vector1.add(new Vector<>(Arrays.asList(1, 2, 3)));
        vector1.add(new Vector<>(Arrays.asList(4, 5, 6)));

        // Populate vector2 with values
        vector2.add(new Vector<>(Arrays.asList(7, 8)));
        vector2.add(new Vector<>(Arrays.asList(9, 10)));
        vector2.add(new Vector<>(Arrays.asList(11, 12)));

        Vector<Vector<Integer>> result = MatrixMultiplication(vector1, vector2);

        // Printing the result matrix
        for (Vector<Integer> row : result) {
            System.out.println(row);
        }
    }
}
