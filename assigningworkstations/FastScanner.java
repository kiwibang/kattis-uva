package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

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
        // get number of researchers, n
        int n = FS.nextInt();
        // get the number of minutes of inactivity
        int m = FS.nextInt();
        // result array to keep the researchers
        int[][] intervals = new int[n][2];
        int index = 0;
        // loop over the n lines
        for (int i = 0; i < n; i++) {
            // get a
            int a = FS.nextInt();
            // get s
            int s = FS.nextInt();
            // add to the solution
            intervals[index++] = new int[] { a, s };
        }
        // create the new solution object
        Solution s = new Solution(n, m, intervals);
        System.out.println(s.solve());
    }
}