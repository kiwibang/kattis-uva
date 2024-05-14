package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    private static final int STUDENTS_COUNT = 20;
    // read the inputs
    public static void main(String[] args) throws IOException {
        // get the number of data sets
        int n = FS.nextInt();
        for (int i = 0; i < n; i++) {
            int[] students = new int[STUDENTS_COUNT];
            int id = FS.nextInt();
            for (int j = 0; j < STUDENTS_COUNT; j++) {
                students[j] = FS.nextInt();
            }
            System.out.println(id + " " + insertionSortAndCount(students));
        }
    }

    private static int insertionSortAndCount(int[] arr) {
        int res = 0;
        // arr[0:0] is trivially sorted => can start from index 1 element
        for (int i = 1; i < STUDENTS_COUNT; i++) {
            int curr = arr[i];
            // find out where to insert the current student in
            // the sorted subarray
            int j = i - 1;
            while (j >= 0 && arr[j] > curr) {
                arr[j + 1] = arr[j];
                res++; // count the number of steps taken back by each student
                j--;
            }
            // at this point, curr <= arr[j] => place the current element here
            arr[j + 1] = curr;
        }
        // return the total number of steps taken back
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