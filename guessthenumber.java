package org.example;

import java.io.IOException;
import java.util.Scanner;

public class Solution {
    // read the inputs
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int low = 1;
        int high = 1000;
        while (low <= high) {
            int mid = (low + high) / 2;
            System.out.println(mid);
            String response = sc.next();
            if (response.equals("correct")) {
                return;
            } else if (response.equals("lower")) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            // flush standard out as instructed
            System.out.flush();
        }
    }
}