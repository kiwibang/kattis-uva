import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class uva00893 {
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
        int daystoadd;
        int days;
        int months;
        int year;
        while (true) {
            daystoadd = FS.nextInt();
            days = FS.nextInt();
            months = FS.nextInt();
            year = FS.nextInt();
            if (daystoadd == 0 && days == 0 && months == 0 && year == 0) {
                break;
            }
            GregorianCalendar date = new GregorianCalendar(year, months - 1, days);
            date.add(Calendar.DATE, daystoadd);
            System.out.println(date.get(Calendar.DATE) + " " + (date.get(Calendar.MONTH) + 1) + " " + date.get(Calendar.YEAR));
        }
    }
}