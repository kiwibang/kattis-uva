package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.math.BigInteger;

public class wizardofodds {
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

        static Long nextLong() throws IOException {
            String out = next();
            try {
                return Long.parseLong(out);
            } catch (NumberFormatException e) {
                throw new NumberFormatException("lol");
            }
        }
    }

    public static void main(String[] args) throws IOException {
        String a = FS.next(), b = FS.next();
        BigInteger n = new BigInteger(a), k = new BigInteger(b), t = new BigInteger("350"), base = new BigInteger("2");
        if (k.compareTo(t) >= 0) {
            System.out.println("Your wish is granted!");
        } else {
            if (base.pow(k.intValue()).compareTo(n) >= 0) {
                System.out.println("Your wish is granted!");
            } else {
                System.out.println("You will become a flying monkey!");
            } 
        }
    }
}
