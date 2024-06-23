import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class uva11356 {
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
        int t = FS.nextInt(), daystoadd;
        String date;
        for (int tc = 1; tc <= t; ++tc) {
            // make the initial string
            StringBuilder res = new StringBuilder("Case ");
            res.append(tc);
            res.append(": ");

            // read in the input
            date = FS.next();
            daystoadd = FS.nextInt();

            // process the input
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MMMM-dd", Locale.ENGLISH);
            LocalDate d = LocalDate.parse(date, formatter);
            LocalDate newDate = d.plusDays(daystoadd);
            String formattedDate = newDate.format(formatter);
            res.append(formattedDate);

            // print out the result
            System.out.println(res);
        }
    }
}
