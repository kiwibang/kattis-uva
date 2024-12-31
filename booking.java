import java.io.BufferedReader;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Event {
    private LocalDateTime time;
    private int type;

    public Event(LocalDateTime time, int type) {
        this.time = time;
        this.type = type;
    }

    public LocalDateTime getTime() {
        return time;
    }

    public int getType() {
        return type;
    }
}

public class booking {
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
        int t = FS.nextInt();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        while (t-- > 0) {
            int b = FS.nextInt(), c = FS.nextInt();
            int cleanh = c / 60, cleanm = c % 60;
            String bookingid, startdate, starttime, enddate, endtime, rawstr;
            ArrayList<Event> bookings = new ArrayList<>();
            for (int i = 0; i < b; ++i) {
                // read in the current booking details
                bookingid = FS.next();
                startdate = FS.next();
                starttime = FS.next();
                enddate = FS.next();
                endtime = FS.next();
                // create datetime strings
                LocalDateTime startt = LocalDateTime.parse(startdate + " " + starttime, formatter);
                LocalDateTime endt = LocalDateTime.parse(enddate + " " + endtime, formatter);
                // add cleaning time to the end time
                endt = endt.plusHours(cleanh).plusMinutes(cleanm);
                // add the times to the list
                bookings.add(new Event(startt, 1));
                bookings.add(new Event(endt, -1));
            }
            // calculate min number of rooms needed
            // sort the list of intervals by start time
            bookings.sort(Comparator.comparing(Event::getTime));
            Collections.sort(bookings, new Comparator<Event>(){
            @Override
            public int compare(Event a, Event b) {
                return a.getTime().isEqual(b.getTime()) ? a.getType() - b.getType() : a.getTime().compareTo(b.getTime());
            }
            });
            int mx = 0, res = 0;
            // calculate the minimum
            for (int i = 0; i < bookings.size(); ++i) {
                Event curr = bookings.get(i);
                res += curr.getType();
                if (res > mx) {
                    mx = res;
                }
            }
            System.out.println(mx);
        }
    }
}
