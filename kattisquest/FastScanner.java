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
        // init solution
        Solution s = new Solution();
        // get n
        int n = FS.nextInt();
        // loop over
        for (int i = 0 ; i < n; ++i) {
            // take command
            String command = FS.next();
            // case where add
            if (command.charAt(0) == 'a') {
                // take energy
                int energy = FS.nextInt();
                // take value
                int value = FS.nextInt();
                // add value
                s.add(energy, value);
            } else {
                int energy = FS.nextInt();
                System.out.println(s.query(energy));
            }
        }
    }
}