package org.example;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
    private final int n;
    private final int m;
    private final int[][] intervals;
    public Solution(int n, int m, int[][] intervals) {
        this.n = n;
        this.m = m;
        // sort the researchers by arrival time
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        this.intervals = intervals;
    }

    // idea: greedy algo whose degree of success hinges on minimising the number
    // of unlocks needed
    public int solve() {
        /* set up the priority queue that will hold unused AND unlocked computers that are
         * the supercomputer centre is not open!!!
         * note that this pq will hold the locking time for all the currently
         * unused and unlocked computers
         * invariant: at any time t, the pq will hold all the currently used computers
         * that are unlocked and unused
         */
        PriorityQueue<Integer> unusedComputers = new PriorityQueue<>();
        /* set up the priority queue that will store the computers that researchers
         * are currently using, where the end time is stored
         * will be empty cos no researcher has arrived yet => init invariant is true
         */
        PriorityQueue<int[]> usingComputers = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        // result variable to keep track of the minimal number of unlocks needed
        int res = 0;

        // then we loop over all the timings that the researchers will arrive\
        for (int i = 0; i < n; i++) {
            /*
             * get the start time and how long the researcher is going to use the
             * computer
             */
            int a = intervals[i][0], s = intervals[i][1];
            /*
             * since there might be researchers that have already been done using
             * their computers, these computers are now unused and unlocked,
             * hence we can add these computers to the usedComputers
             */
            while (!usingComputers.isEmpty() && usingComputers.peek()[0] < a) {
                int[] data = usingComputers.poll();
                // get the time that the computer will be unlocked
                int lockTime = data[1];
                // else if not locked yet, just add to the unusedComputers pq
                unusedComputers.offer(lockTime);
            }
            /*
             * pop any unused AND unlocked computers that will be locked
             * now, so we maintain the invariant of this pq
             */
            while (!unusedComputers.isEmpty() && unusedComputers.peek() + 1 < a) {
                unusedComputers.poll();
            }
            /*
             * since we are going for a greedy approach, we can save 1 unlock
             * by assigning the current researcher to an available computer that has not
             * been locked yet. this computer should also be the one that
             * is the closest to being locked. this condition is already taken
             * care for us by virtue of the pq
             */
            if (!unusedComputers.isEmpty()) {
                unusedComputers.poll();
                // increment the res since we just saved 1 unlock :)
                res++;
            }
            int endTime = a + s - 1;
            int lockTime = endTime + m;
            // researcher is now using a computer => place the time when the researcher
            // finishes to the pq
            usingComputers.offer(new int[] { endTime, lockTime });
        }
        return res;
    }
}
