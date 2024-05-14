import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DingDongDitch {
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

    public static void main(String[] args) throws IOException {
        int N = FS.nextInt();
        int Q = FS.nextInt();
        long[] houses = new long[N + 1];
        int[] friends = new int[Q];
        for (int i = 1; i <= N; i++) {
            houses[i] = FS.nextInt();
        }
        for (int i = 0; i < Q; i++) {
            friends[i] = FS.nextInt();
        }
        Arrays.sort(houses);
        for (int i = 1; i <= N; i++) {
            houses[i] = houses[i - 1] + houses[i];
        }
        for (int i = 0; i < Q; i++) {
            System.out.println(houses[friends[i]]);
        }
    }
}
