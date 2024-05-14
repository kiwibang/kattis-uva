package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Solution {
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

    private static final long MOD = 1_000_000_000;
    // read the inputs
    public static void main(String[] args) throws IOException {
        int P = FS.nextInt();
        for (int i = 0; i < P; i++) {
            int id = FS.nextInt();
            System.out.println(id + " " + solve(FS.nextLong()));
        }
    }

    // memoised fib function
    private static long solve(long n) {
        // create the base matrix
        long[][] mat = new long[2][2];
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        FibMatrix res = new FibMatrix(mat);
        FibMatrix ans = FibMatrix.matrixPower(res, n);
        return ans.mat[0][1];
    }

    private static class FibMatrix {
        private final long[][] mat;
        private FibMatrix(long[][] mat) {
            this.mat = mat;
        }

        private static final long MOD = 1_000_000_000;
        // adapted from CP4 book 2: section 5.8
        // ive translated the C++ code given in the example into Java instead
        // could not understand the optimization hence went with unoptimized version
        private static FibMatrix multiply(FibMatrix a, FibMatrix b) {
            // 2 x 2 init to 0
            FibMatrix res = new FibMatrix(new long[2][2]);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    // cross pdt
                    for (int k = 0; k < 2; k++) {
                        res.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
                        res.mat[i][j] = (res.mat[i][j] % MOD);
                    }
                }
            }
            return res;
        }

        // matrix power, also adapted from the same section as multiple function
        // translated into Java as well
        private static FibMatrix matrixPower(FibMatrix base, long p) {
            if (p <= 1) {
                return base;
            }
            FibMatrix res = new FibMatrix(new long[2][2]);
            // make identity matrix
            res.mat[0][0] = 1;
            res.mat[1][1] = 1;
            while (p > 0) {
                if ((p & 1) == 1) {
                    res = multiply(res, base);
                }
                base = multiply(base, base);
                p >>= 1;
            }
            return res;
        }
    }
}