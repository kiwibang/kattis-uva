package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.math.BigInteger;

public class threepowers {
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
        String curr, cstr;
        BigInteger c, base = new BigInteger("3");
        while (true) {
            curr = FS.next();
            if (curr.equals("0")) break;
            c = new BigInteger(curr).subtract(BigInteger.ONE);
            cstr = c.toString(2);
            StringBuilder sb = new StringBuilder("{ ");
            ArrayList<String> nums = new ArrayList<>();
            for (int i = cstr.length() - 1; i >= 0; --i) {
                if (cstr.charAt(i) == '1') {
                    int p = cstr.length() - 1 - i;
                    nums.add(base.pow(p).toString());
                }
            }
            for (int i = 0; i < nums.size(); ++i) {
                sb.append(nums.get(i).toCharArray());
                if (i < nums.size() - 1) sb.append(", ");
            }
            if (nums.size() > 0) sb.append(' ');
            sb.append('}');
            System.out.println(sb.toString());
        }
    }
}
