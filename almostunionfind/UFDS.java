package org.example;

import java.util.ArrayList;
import java.util.List;

// consider hint: no need to modify the parent data structure
public class UFDS {
    // fields
    private final int[] parent;
    private final int[] next;
    private final int[] size;
    private final long[] sum;
    private final int n;
    // constructor
    public UFDS(int n) {
        this.n = n;
        this.parent = new int[n + 1];
        this.next = new int[n + 1];
        this.size = new int[n + 1];
        this.sum = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            this.parent[i] = i;
            this.next[i] = i;
            this.size[i] = 1;
            this.sum[i] = i;
        }
    }

    public int findSet(int i) {
        // get the set id of i
        int currentParent = next[i];
        while (currentParent != parent[currentParent]) {
            currentParent = parent[currentParent];
        }
        next[i] = currentParent;
        return currentParent;
    }

    // isSameSet method
    public boolean isSameSet(int p, int q) {
        return findSet(p) == findSet(q);
    }

    // union method
    public void union(int p, int q) {
        int x = findSet(p), y = findSet(q);
        // gc: same set => don't do anything
        if (x == y) { return; }
        // check rank
        if (this.size[x] > this.size[y]) { // case where p tree is larger than q tree
            // connect q to p
            this.parent[y] = x;
            // update sum and size of set of y
            this.sum[x] += this.sum[y];
            this.size[x] += this.size[y];
        } else { // case where p tree is smaller than or equals to the q tree
            // connect p to q
            this.parent[x] = y;
            // update sum and size of set of x
            this.sum[y] += this.sum[x];
            this.size[y] += this.size[x];
        }
    }

    // move method; moves p to q
    public void move(int p, int q) {
        // same set => don't do anything
        if (isSameSet(p, q)) { return; }
        // find the god nodes of p and q
        int godP = findSet(p);
        int godQ = findSet(q);
        // since we are removing 1 element, we decrement the size of the set of P by 1
        // and increment the size of the set of Q by 1
        size[godP]--;
        size[godQ]++;
        // since we are removing p from the set containing p
        // and moving it into the set containing q, we
        // decrement the sum of the set containing p by p
        // and increment the sum of the set containing q by p
        sum[godP] -= p;
        sum[godQ] += p;
        // then we actually attach p to the set containing q
        // using the extra parent array
        next[p] = godQ;
    }

    public long getSum(int p) {
        return sum[findSet(p)];
    }

    public int getSize(int p) {
        return size[findSet(p)];
    }
}
