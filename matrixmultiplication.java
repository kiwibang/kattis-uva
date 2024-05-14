import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class MatrixMultiplication {
    // homemade FastScanner class to process the input
    static class FS {
        static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer st=new StringTokenizer("");

        static String next() throws IOException {
            while (!st.hasMoreTokens()) { st=new StringTokenizer(br.readLine()); }
            return st.nextToken();
        }

        static int nextInt() throws IOException {
            String out = next();
            try {
                return Integer.parseInt(out);
            } catch (NumberFormatException e) {
                throw new NumberFormatException("lol");
            }
        }

        static float nextFloat() throws IOException {
            String out = next();
            try {
                return Float.parseFloat(out);
            } catch (NumberFormatException e) {
                throw new NumberFormatException("lol");
            }
        }
    }

    public static final int NUM_LOOPS = 9;
    public static int n;
    public static int x;
    public static int y;
    public static int m;
    public static void main(String[] args) throws IOException {
        int testCaseCount = FS.nextInt();
        for (int curr = 0; curr < testCaseCount; curr++) {
            // get the dimensions of the matrices
            MatrixMultiplication.n = FS.nextInt();
            MatrixMultiplication.x = FS.nextInt();
            MatrixMultiplication.y = FS.nextInt();
            MatrixMultiplication.m = FS.nextInt();
            // if the dimensions do not match, print error as specified
            boolean executeFrievalds = true;
            if (x != y) {
                executeFrievalds = false;
                System.out.println("Inner matrix dimensions must agree");
                // note we still need to scan away all the values of the input matrices
                // so we do not return here
            }
            // create the 3 matrices
            int[][] A = new int[n][x];
            int[][] B = new int[y][m];
            int[][] C = new int[n][m];
            // read the values into the matrices, starting with A
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < x; j++) {
                    A[i][j] = FS.nextInt();
                }
            }
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < m; j++) {
                    B[i][j] = FS.nextInt();
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C[i][j] = FS.nextInt();
                }
            }
            // then execute Frievald's algo 128 times, this gives us a probability of
            // a wrong answer to be about 1 / 128 = 0.0078125
            if (!executeFrievalds) {
                continue;
            }
            boolean isWrong = false;
            for (int i = 0; i < NUM_LOOPS; i++) {
                if (!frievalds(A, B, C)) {
                    isWrong = true;
                    break;
                }
            }
            if (isWrong) {
                System.out.println("WA");
            } else {
                System.out.println("AC");
            }
        }
    }

    static Random r = new Random();
    public static boolean frievalds(int[][] A, int[][] B, int[][] C) {
        // generate a random vector of length m, say v
        int[] v = new int[m];
        for (int i = 0; i < m; i++) {
            v[i] = r.nextInt(2);
        }
        // then matrix multiply Bv, to get a vector of dimensions y x 1, say v'
        int[] vPrime = new int[y];
        for (int i = 0; i < y; i++) {
            // multiply the current row with v
            for (int j = 0; j < m; j++) {
                vPrime[i] += (B[i][j] * v[j]);
            }
        }
        // then matrix multiply Av', to get a vector of dimensions n x 1, say v''
        int[] vPrimePrime = new int[n];
        for (int i = 0; i < n; i++) {
            // multiply the current row with v
            for (int j = 0; j < x; j++) {
                vPrimePrime[i] += (A[i][j] * vPrime[j]);
            }
        }
        // then matrix multiply Cv, to get a vector of dimension n X 1, say v'''
        int[] vPrimePrimePrime = new int[n];
        for (int i = 0; i < n; i++) {
            // multiply the current row with v
            for (int j = 0; j < m; j++) {
                vPrimePrimePrime[i] += (C[i][j] * v[j]);
            }
        }
        return Arrays.equals(vPrimePrime, vPrimePrimePrime);
    }
}
