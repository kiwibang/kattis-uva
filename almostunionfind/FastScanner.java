package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class FastScanner {

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
    }

    // main method
    public static void main(String[] args) {
        try {
            while (true) {
                // get the number of integers, and number of commands, respectively
                int n = FS.nextInt(), m = FS.nextInt();
                // create the solution object from which we can call the methods
                UFDS ufds = new UFDS(n);
                // loop over the commands
                for (int i = 0; i < m; i++) {
                    // get the command id
                    int commandId = FS.nextInt();
                    int p = 0, q = 0;
                    // switch case to call the solution based on the command id
                    switch (commandId) {
                        case 1: // union command
                            // get p and q
                            p = FS.nextInt();
                            q = FS.nextInt();
                            ufds.union(p, q);
                            break;
                        case 2: // move command
                            // get p and q
                            p = FS.nextInt();
                            q = FS.nextInt();
                            ufds.move(p, q);
                            break;
                        case 3: // return # of elements and sum of elements in the set containing p
                            p = FS.nextInt();
                            int size = ufds.getSize(p);
                            long sum = ufds.getSum(p);
                            System.out.println(size + " " + sum);
                            break;
                    }
                }
            }
        } catch (Exception e) {
        }
    }
}