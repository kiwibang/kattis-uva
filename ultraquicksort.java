package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    // read the inputs
    public static void main(String[] args) throws IOException {
        // read the input
        int count = FS.nextInt();
        int[] input = new int[count];
        for (int i = 0; i < count; i++) {
            input[i] = FS.nextInt();
        }
        // print the output
        System.out.print(solve(input, 0, count - 1));
    }

    // main solver function: use D&C
    private static long solve(int[] input, int l, int r) {
        // base case: just 1 element
        if (l >= r) {
            return 0;
        }
        // divide: count the out-of-order pairs on the left and right
        int mid = (l + r) / 2;
        // conquer
        long leftCount = solve(input, l, mid); // sort left
        long rightCount = solve(input, mid + 1, r); // sort right
        // combine
        long centreCount = merge(input, l, mid, r);
        return leftCount + rightCount + centreCount;
    }

    // adapted from CLRS 4th ed. chapter 2: MERGE subroutine
    // pseudocode translated into Java code
    private static long merge(int[] input, int left, int mid, int right) {
        int[] larr = Arrays.copyOfRange(input, left, mid + 1);
        int[] rarr = Arrays.copyOfRange(input, mid + 1, right + 1);
        int i = 0, j = 0, k = left; 
        long res = 0;
        while (i < larr.length && j < rarr.length) {
            if (larr[i] <= rarr[j]) {
                input[k++] = larr[i++];
            } else {
                input[k++] = rarr[j++];
                res += (mid + 1) - (left + i);
            }
        }
        while (i < larr.length) {
            input[k++] = larr[i++];
        }
        while (j < rarr.length) {
            input[k++] = rarr[j++];
        }
        return res;
    }
    // scanner class
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
}