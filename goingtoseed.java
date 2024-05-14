import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class goingtoseed2 {
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

    static int LIM;
    private static void helper(int low, int high) throws IOException {
        if (low >= high) {
            System.out.println("A " + high);
            return;
        }

        int len = high - low + 1;
        // gc: 4 or less array
        if (len <= 4) {
            int c;
            int d;
            if (len == 4) {
                System.out.println("Q" + " " + low + " " + (low + 1) + " " + (low + 1) + " " + (high - 1));
                System.out.flush();
                c = FS.nextInt();
                d = FS.nextInt();
                if (c == 0 && d == 0) {
                    System.out.println("A " + high);
                } else if (c == 1 && d == 0) {
                    System.out.println("A " + low);
                } else if (c == 0 && d == 1) {
                    System.out.println("A " + (high - 1));
                } else {
                    System.out.println("A " + (low + 1));
                }
                return;
            } else if (len == 3) {
                System.out.println("Q" + " " + low + " " + low + " " + (low + 1) + " " + (low + 1));
                System.out.flush();
                c = FS.nextInt();
                d = FS.nextInt();
                if (c == 0 && d == 0) {
                    System.out.println("A " + high);
                } else if (c == 1 && d == 0) {
                    System.out.println("A " + low);
                } else if (c == 0 && d == 1) {
                    System.out.println("A " + (low + 1));
                }
                return;
            } else if (len == 2) {
                System.out.println("Q" + " " + low + " " + low + " " + high + " " + high);
                System.out.flush();
                c = FS.nextInt();
                d = FS.nextInt();
                if (c == 1) {
                    System.out.println("A " + low);
                    return;
                }
                if (d == 1) {
                    System.out.println("A " + high);
                }
                return;
            }
            return;
        }

        // split the array into 4 pieces
        int div2 = low + (high - low) / 2;
        int div1 = 1 + low + (div2 - low) / 2;
        int div3 = div2 + (high - div2) / 2;
        // ask question
        System.out.println("Q" + " " + low + " " + div2 + " " + div1 + " " + div3);
        System.out.flush();
        int a = FS.nextInt();
        int b = FS.nextInt();
        // case where no rustling on either side => seedling can only jump within the fourth section of trees
        if (a == 0 && b == 0) {
            if (div3 + 1 == high) {
                System.out.println("A " + high);
                return;
            }
            // look in the fourth n / 4 section, as well as div3 since seedling could jump to div3 in the next half-hour
            low = div3;
            // account for the fact that seedling may jump from high to high + 1 if high < N
            high = Math.min(high + 1, goingtoseed2.LIM);
        } else if (a == 1 && b == 0) { // rustling on Applejack's side => only jump within Applejack's side
            if (low == div1 - 1) {
                System.out.println("A " + low);
                return;
            }
            // account for the fact that seedling may jump from low to low - 1 in the next half-hour
            low = Math.max(low - 1, 1);
            // look on the first n / 4 size section, as well as div1 since seedling could jump to div1 in the next half-hour
            high = div1;
        } else if (a == 0 && b == 1) { // rustling on Apple Bloom's side => only jump within Apple Bloom's side
            if (div2 + 1 == div3) {
                System.out.println("A " + div3);
                return;
            }
            // look on the third n / 4 section, and account for div2
            low = div2;
            // look on div3 + 1 too
            high = Math.min(div3 + 1, goingtoseed2.LIM);
        } else { // rustling on both sides => might have a jump from div1 to div1 - 1 or div2 to div2 + 1
            if (div2 == div1) {
                System.out.println("A " + div1);
                return;
            }
            // look on the second n / 4 section
            low = Math.max(div1 - 1, 1);
            high = Math.min(div2 + 1, goingtoseed2.LIM);
        }
        helper(low, high);
    }

    public static void main(String[] args) throws IOException {
        // read in the number of trees
        int N = FS.nextInt();
        goingtoseed2.LIM = N;
        helper(1, N);
    }
}
