package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
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
    }
    // read the inputs
    public static void main(String[] args) throws IOException {
        String curr;
        while ((curr = FS.br.readLine()) != null) {
            System.out.println(solve(curr));
        }
    }

    private static final BigInteger MOD = new BigInteger("10000");
    // solver function
    private static int solve(String curr) {
        // tokenize the input into the two operands and one operator
        String[] tokens = curr.split(" ");
        // get the last 4 digits of each operand
        BigInteger op1 = new BigInteger(tokens[0]);
        BigInteger op2 = new BigInteger(tokens[2]);
        switch (tokens[1]) {
            case "+":
                return op1.add(op2).mod(MOD).intValue();
            case "*":
                return op1.multiply(op2).mod(MOD).intValue();
            case "^":
                return op1.modPow(op2, MOD).intValue();
        }
        return -1;
    }
}