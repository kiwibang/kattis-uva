import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
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

    private static final double TEST_NUMBER = 1_000_000_007;
    static void mt(int a, float b, float c, float d, int k) {
        // get the watershed function
        double watershed = Math.log(a) / Math.log(b);
        // build the result string
        StringBuilder res = new StringBuilder();
        // check case 1
        if (d < watershed) {
            // gc 0: watershed is a constant => print nothing
            if (watershed == 0) {
                return;
            }
            res.append("n");
            // gc 1: watershed is linear => just print n
            if (watershed == 1) {
                System.out.println(res);
                return;
            }
            res.append("^");
            // gc 2: if the watershed function has an integer power
            if (Math.floor(watershed) == watershed) {
                res.append((int) Math.floor(watershed));
                System.out.println(res);
                return;
            }
            // else, print the watershed function, rounded to 1 d.p
            res.append(String.format("%.1f", watershed));
            System.out.println(res);
            return;
        } else if (d == watershed) { // check case 2
            // append the watershed
            if (watershed == 0) {
            } else if (watershed == 1) {
                res.append("n");
            } else if (Math.floor(watershed) == watershed) {
                res.append("n");
                res.append("^");
                res.append((int) Math.floor(watershed));
            } else {
                res.append("n");
                res.append("^");
                res.append(String.format("%.1f", watershed));
            }
            if (k >= 0) {
                // append the log
                if (k + 1 == 1) {
                    res.append(" log n");
                } else {
                    res.append(" log");
                    res.append("^");
                    res.append(k + 1);
                    res.append(" n");
                }
            } else if (k == -1) {
                res.append(" log log n");
            } else if (k < -1) {
            } else {
                System.out.println("not applicable");
            }
            System.out.println(res);
            return;
        } else if (d > watershed) { // check case 3
            // gc: f(n) does not satisfy the regularity condition
            double coeff = (a * Math.pow((1 / b), d)) * (1 - Math.pow((Math.log(b) / Math.log(TEST_NUMBER)), k));
            if (coeff >= 1) {
                System.out.println("not applicable");
            }
            // append n term of f(n)
            if (d == 0) {
            } else if (d == 1) {
                res.append("n");
            } else if (Math.floor(d) == d) {
                res.append("n");
                res.append("^");
                res.append(((int) Math.floor(d)));
            } else {
                res.append("n");
                res.append("^");
                res.append(String.format("%.1f", d));
            }

            if (k == 0) {
            } else if (k == 1) {
                res.append(" log n");
            } else {
                res.append(" log");
                res.append("^");
                res.append(k);
                res.append(" n");
            }
            System.out.println(res);
            return;
        }
        // if recurrence does not fall into any of the 3 categories, then mt does not apply
        // so print that the mt does not apply to this recurrence, as specified in the question
        System.out.println("not applicable");
    }

    public static void main(String[] args) throws IOException {
        int a = FS.nextInt();
        float b = FS.nextFloat();
        float c = FS.nextFloat();
        float d = FS.nextFloat();
        int k = FS.nextInt();
        mt(a, b, c, d, k);
    }
}