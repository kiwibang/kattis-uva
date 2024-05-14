import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Gourmet {
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
    static int[] memo;
    public static void main(String[] args) throws IOException {
        int M = FS.nextInt();
        int N = FS.nextInt();
        int[] dishes = new int[N];
        memo = new int[M + 1];
        for (int i = 0; i < N; i++) {
            dishes[i] = FS.nextInt();
        }
        System.out.println(solve(M, dishes));
    }
    public static int solve(int remainingTime, int[] dishes) {
        // base case: outta time or outta food
        if (remainingTime < 0) {
            return 0;
        }
        // case where just nice
        if (remainingTime == 0) {
            return 1;
        }
        // case where memo already
        if (memo[remainingTime] != 0) {
            return memo[remainingTime];
        }
        // else, just compute the total number of ways
        for (int dish : dishes) {
            memo[remainingTime] += solve(remainingTime - dish, dishes);
        }
        return memo[remainingTime];
    }
}
