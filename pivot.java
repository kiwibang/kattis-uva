package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.sql.SQLOutput;
import java.util.*;

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
        int n = FS.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = FS.nextInt();
        }
        System.out.println(solve(arr, n));
    }

    private static int solve(int[] arr, int n) {
        // track count of possible pivots
        int res = 0;
        // left pq to be maxheap
        PriorityQueue<Integer> left = new PriorityQueue<>(Collections.reverseOrder());
        // right pq to be minheap
        PriorityQueue<Integer> right = new PriorityQueue<>();
        // add all elements other than the 0th element to the right pq
        for (int i = 1; i < n; i++) {
            right.offer(arr[i]);
        }
        // loop over the elements of the array, check if they can be pivots
        for (int i = 0; i < n; i++) {
            // get the highest left element
            int leftHi = left.isEmpty() ? Integer.MIN_VALUE : left.peek();
            // get the lowest right element
            int rightLo = right.isEmpty() ? Integer.MAX_VALUE : right.peek();
            // case where actually a pivot
            if (leftHi <= arr[i] && arr[i] < rightLo) {
                res++;
            }
            // update the two pqs
            left.offer(arr[i]);
            if (i < n - 1) {
                right.remove(arr[i + 1]);
            }
        }
        return res;
    }

}