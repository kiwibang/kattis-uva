import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

class FastScanner {

    static class FS {
        static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer st=new StringTokenizer("");

        static String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {}
            return st.nextToken();
        }

        static int nextInt() {
            return Integer.parseInt(next());
        }
        static long nextLong() {
            return Long.parseLong(next());
        }
    }

    // main method
    public static void main(String[] args) throws IOException {
        // get m
        int m = FS.nextInt();
        // get n
        int n = FS.nextInt();
        // get k
        int k = FS.nextInt();
        // init solution instance
        Solution s = new Solution(n, m);
//        int[] left = new int[] {3,1,2};
//        int[] right = new int[] {3,1,2};
//        int[] cs = new int[] {2,3,1};
//        int[] maybeLeft = s.getLeft(right, cs);
//        for (int i : maybeLeft) {
//            System.out.print(i);
//        }
//        System.out.println("");
//        int[] maybeRight = s.getRight(left, cs);
//        for (int j : maybeRight) {
//            System.out.print(j);
//        }
        // read the k lines
        for (int i = 0; i < k; ++i) {
            int l = FS.nextInt();
            int r = FS.nextInt();
            // create the constraint array
            int[] constraint = new int[n];
            IntStream.range(0, n).forEach(x -> constraint[x] = FS.nextInt());
            // pass into solution
            System.out.println(s.update(l, r, constraint));
        }
    }
}