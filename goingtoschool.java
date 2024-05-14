import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class GoingToSchool {
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

    public static int[][] dp;
    public static String path;
    public static int n;
    public static void main(String[] args) throws IOException {
        // get the input string
        GoingToSchool.path = FS.next();
        GoingToSchool.n = path.length();
        // then use dp table, where dp[i] is the minimum number of crossings
        // needed to get from her house to the position right after crossing i
        GoingToSchool.dp = new int[2][n + 1];
        for (int[] d : dp) {
            Arrays.fill(d, 2000);
        }
        dp[0][0] = 0;
        dp[1][0] = 1;
        for (int i = 1; i <= n; i++) {
            // get the current type of crossing
            char currCrossing = path.charAt(i - 1);
            // deal with the cases
            if (currCrossing == 'B') {
                dp[0][i] = 1 + Math.min(dp[0][i - 1], 1 + dp[1][i - 1]);
                dp[1][i] = 1 + Math.min(1 + dp[0][i - 1], dp[1][i - 1]);
            } else if (currCrossing == 'N') {
                dp[1][i] = Math.min(1 + dp[0][i - 1], dp[1][i - 1]);
                dp[0][i] = 1 + Math.min(dp[0][i - 1], dp[1][i]);
            } else {
                dp[0][i] = Math.min(dp[0][i - 1], 1 + dp[1][i - 1]);
                dp[1][i] = 1 + Math.min(dp[0][i], dp[1][i - 1]);
            }
        }
//        helperRecursive(n, 0);
//        System.out.println(Arrays.deepToString(dp));
        System.out.println(dp[0][n]);
    }

    public static int helperRecursive(int i, int isNorth) {
        if (i <= 0) {
            return dp[isNorth][0];
        }
        if (dp[isNorth][i] != 2000) {
            return dp[isNorth][i];
        }
        if (i == n && isNorth == 0) {
            helperRecursive(n, 1);
        }
        char currCrosswalk = path.charAt(i - 1);
        if (currCrosswalk == 'B') {
            dp[isNorth][i] = isNorth == 0
                ? 1 + Math.min(helperRecursive(i - 1, 0), 1 + helperRecursive(i - 1, 1))
                : 1 + Math.min(1 + helperRecursive(i - 1, 0), helperRecursive(i - 1, 1));
        } else if (currCrosswalk == 'N') {
            dp[isNorth][i] = isNorth == 0
                ? 1 + Math.min(helperRecursive(i - 1, 0), helperRecursive(i, 1))
                : Math.min(1 + helperRecursive(i - 1, 0), helperRecursive(i - 1, 1));
        } else {
            dp[isNorth][i] = isNorth == 0
                ? Math.min(helperRecursive(i - 1, 0), 1 + helperRecursive(i - 1, 1))
                : 1 + Math.min(helperRecursive(i, 0), helperRecursive(i - 1, 1));
        }
        return dp[isNorth][i];
    }
}
