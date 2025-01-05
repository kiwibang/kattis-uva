package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.math.BigInteger;

public class generalizedrecursivefunctions {
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

        static String nextLine() throws IOException {
            String res = br.readLine();
            return res;
        }
    }

    static BigInteger def = new BigInteger("-1");
    static BigInteger c;
    static BigInteger d;
    static BigInteger f(int x, int y, BigInteger[][] cache, int[] abpair) {
        if (x <= 0 || y <= 0) {
            return d;
        }
        if (!cache[x][y].equals(def)) {
            return cache[x][y];
        }
        BigInteger res = new BigInteger("0"); 
        for (int i = 0; i < abpair.length; i += 2) {
            res = res.add(f(x - abpair[i], y - abpair[i + 1], cache, abpair));
        }
        res = res.add(c);
        cache[x][y] = res;
        return res;
    }
    static void solve() throws IOException {
        String a = FS.nextLine(), b = FS.nextLine();
        String[] abpairs = a.split(" "), inputs = b.split(" ");
        int[] abpair = new int[abpairs.length - 2];
        int[] inputss = new int[inputs.length];
        c = new BigInteger(abpairs[abpairs.length - 2]);
        d = new BigInteger(abpairs[abpairs.length - 1]);
        BigInteger[][] cache = new BigInteger[101][101];
        for (int i = 0; i < abpair.length; ++i) {
            abpair[i] = Integer.parseInt(abpairs[i]);
        }
        for (int i = 0; i < inputs.length; ++i) {
            inputss[i] = Integer.parseInt(inputs[i]);
        }
        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                cache[i][j] = new BigInteger("-1");
            }
        }
        for (int i = 0; i < inputss.length; i += 2) {
            System.out.println(f(inputss[i], inputss[i + 1], cache, abpair));
        }
    }
    public static void main(String[] args) throws IOException {
        int n = FS.nextInt();
        for (int i = 0; i < n; ++i) {
            solve();
            if (i < n - 1) {
                System.out.println("");
            }
        }
    }
}
