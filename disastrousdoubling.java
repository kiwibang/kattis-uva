package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.math.BigInteger;

public class disastrousdoubling {
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

    static BigInteger MOD = new BigInteger("1000000007");
    public static void main(String[] args) throws IOException {
        int n = FS.nextInt();
        BigInteger count = BigInteger.ONE;
        String need;
        for (int i = 0; i < n; ++i) {
            count = count.shiftLeft(1);
            need = FS.next();
            BigInteger temp = new BigInteger(need);
            count = count.subtract(temp);
            if (count.compareTo(BigInteger.ZERO) < 0) {
                System.out.println("error");
                return;
            }
        }
        count = count.mod(MOD);
        System.out.println(count);
    }
}
