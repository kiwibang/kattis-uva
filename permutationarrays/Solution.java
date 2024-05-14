import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

public class Solution {

    // represents an edge
    private static class Edge {
        // weight
        private final int[] weight;
        // end node
        private final int r;
        // constructor
        private Edge(int[] weight, int r) {
            this.weight = weight;
            this.r = r;
        }
    }

    // class that implements the UFDS
    private static class UnionFind {
        // parent array
        private final int[] parent;
        // size array
        private final int[] size;
        // number of connected components
        private int cc;
        // constructor
        private UnionFind(int m) {
            this.parent = new int[m + 1];
            this.size = new int[m + 1];
            // set the parent to itself. everything is a singleton
            for (int i = 0; i < m + 1; ++i) {
                this.parent[i] = i;
                this.size[i] = 1;
            }
            // set number of cc
            cc = m + 1;
        }

        // union operation with weighted union
        private void union(int a, int b) {
            // do union-by-weight
//            while (this.parent[a] != a) { a = this.parent[a]; }
//            while (this.parent[b] != b) { b = this.parent[b]; }
            a = this.find(a);
            b = this.find(b);
            // gc: both in same cc
            if (a == b) {
                // just return the cc unchanged
                return;
            }

            // case where set a is larger than set b
            if (size[a] > size[b]) {
                // change the parent of b to a
                parent[b] = a;
                // update the size of a
                size[a] += size[b];
            } else { // case where the size of set a is smaller than set b
                // change the parent of a to b
                parent[a] = b;
                // update the size of b
                size[b] += size[a];
            }
            // at this point, we know that two different connected components have been unioned into one.
            // update the number of connected components
            this.cc -= 1;
            // return the number of connected components at the end
        }

        // find operation with path compression
        private int find(int a) {
            // save the root
            int root = a;
            // look for the root node of the cc
            while (root != parent[root]) { root = parent[root]; }
            // change all the nodes parent to the parent
//            while (a != parent[a]) {
//                // save the old parent
//                int temp = parent[a];
//                // set the parent of a as the root
//                parent[a] = root;
//                // update a
//                a = temp;
//            }
            // return the parent at the end
            return root;
        }
    }

    // identity array, consisting of the natural numbers from 1 to the given n
    private final int[] id;
    // length m permutation array. set as a prefix * array
    private final int[][] permutations;
    private final int m;
    // adjacency matrix
//    private final HashMap<Integer, HashMap<Integer, int[]>> adjList;
    private final ArrayList<ArrayList<Edge>> adjList;
    // store n factorial
    private BigInteger nFac;
    //    private int nFac;
    // UFDS to count the number of cc
    private final UnionFind uf;
    // save whether the constraints are consistent
    private boolean isConsistent;
    private final int n;

    public Solution(int n, int m) {
        this.n = n;
        this.id = new int[n];
        // create identity array
        for (int j = 0; j < n; ++j) {
            this.id[j] = j + 1;
        }

        // create permutations arrays
        this.permutations = new int[m + 1][];
        // set first element to the identity
        this.permutations[0] = this.id;

        this.m = m;

        // get an adjacency list
        this.adjList = new ArrayList<>(m + 1);
        for (int i = 0; i < m + 1; ++i) {
            this.adjList.add(i, new ArrayList<>());
        }

        // pre-compute the factorial
        this.nFac = new BigInteger("1");
//         this.nFac = 1;
        for (int i = 1; i <= n; ++i) {
            this.nFac = this.nFac.multiply(BigInteger.valueOf(i));
//             this.nFac *= i;
        }

        // init the UFDS
        this.uf = new UnionFind(this.m);

        // init consistent
        this.isConsistent = true;
    }

    public int update(int l, int r, int[] constraint) {
        // check if the constraint is a permutation in the first place. if not, the permutations array will not be consistent
        this.isConsistent = this.isConsistent && this.checkDuplicates(constraint);
        // if not consistent in the first place, just return 0
        if (!this.isConsistent) { return 0; }

        // get the parent of the connected component
        int lparent = this.uf.find(l - 1);
        int rparent = this.uf.find(r);
        // get the parent of the cc containing the identity
        int iparent = this.uf.find(0);
        // get smaller cc
        int smaller = this.uf.size[lparent] < this.uf.size[rparent]
                ? l - 1
                : r;
//        // get larger cc
//        int larger = this.uf.size[lparent] < this.uf.size[rparent]
//                ? r
//                : l - 1;

        // case where the edge is between 2 connected components
        if (lparent == rparent) {
            // get right weight
            int[] maybeRightWeight = this.op(this.permutations[l - 1], constraint);
            // get left weight
            int[] maybeLeftWeight = this.findAssignment(constraint, this.permutations[r]);
            // check consistency
            this.isConsistent = Arrays.equals(this.permutations[r], maybeRightWeight)
                    && Arrays.equals(this.permutations[l - 1], maybeLeftWeight);
//            // perform op
//            int[] maybeWeight = this.op(this.permutations[l - 1], this.permutations[r]);
//            // check if equals to the constraint
//            this.isConsistent = Arrays.equals(constraint, maybeWeight);
            // if become not consistent, just return 0. don't need to add any edges
            if (!this.isConsistent) { return 0; }
        } else { // case where the edge is between 2 separate components
//            // case where left smaller
//            if (smaller == l - 1) {
//                // assign right a value if it is null
//                this.permutations[r] = this.permutations[r] == null
//                        ? this.id
//                        : this.permutations[r];
//                // reverse assign the left
//                this.permutations[l - 1] = this.getLeft(this.permutations[r], constraint);
//                // check for consistency
//                this.isConsistent = this.checkConsistency(l - 1);
//            } else { // case where right smaller
//                // assign left a value if it is null
//                this.permutations[l - 1] = this.permutations[l - 1] == null
//                        ? this.id
//                        : this.permutations[l - 1];
//                // assign the right
//                this.permutations[r] = this.getRight(this.permutations[l - 1], constraint);
//                // check for consistency
//                this.isConsistent = this.checkConsistency(r);
//            }
            // if both null
            if (this.permutations[l - 1] == null && this.permutations[r] == null) {
                // set the l - 1 to id
                this.permutations[l - 1] = this.id;
                // set r to id * constraint = constraint
                this.permutations[r] = this.op(this.id, constraint);
//                this.isConsistent = this.checkConsistency(r);
            } else if (this.permutations[l - 1] == null && this.permutations[r] != null) { // if left null, right not null
                // note: the left will never be the identity since the element at index 0 is already this.id
                // hence safe to reverse engineer the left
                // this case occurs when a) left is not the identity, and b) left is a singleton
                this.permutations[l - 1] = this.findAssignment(constraint, this.permutations[r]);
//                this.isConsistent = this.checkConsistency(l - 1);
            } else if (this.permutations[l - 1] != null && this.permutations[r] == null) { // if left not null, right null
                // assign right
                this.permutations[r] = this.op(this.permutations[l - 1], constraint);
//                this.isConsistent = this.checkConsistency(r);
            } else { // if both not null
                // case where l - 1 has id
                if (lparent == iparent) {
                    // perform op on the right
                    this.permutations[r] = this.op(this.permutations[l - 1], constraint);
                    // update assignments on the right
                    this.isConsistent = this.checkConsistency(r);
                } else if (rparent == iparent) { // case where r has id
                    // perform assignment on the left
                    this.permutations[l - 1] = this.findAssignment(constraint, this.permutations[r]);
                    // update assignments on the left
                    this.isConsistent = this.checkConsistency(l - 1);
                } else { // case where neither l - 1 nor r has id
                    // case where l - 1 set is smaller
                    if (smaller == l - 1) {
                        // perform assignment on left
                        this.permutations[l - 1] = this.findAssignment(constraint, this.permutations[r]);
                        // check left
                        this.isConsistent = this.checkConsistency(l - 1);
                    } else { // case where l - 1 set is larger
                        // perform op on right
                        this.permutations[r] = this.op(this.permutations[l - 1], constraint);
                        // update right
                        this.isConsistent = this.checkConsistency(r);
                    }
                }
            }
            // count the number of connected components and update if neccessary
            this.uf.union(lparent, rparent);
        }

        // add to the adjacency list if valid
        this.adjList.get(l - 1).add(new Edge(constraint, r));
        this.adjList.get(r).add(new Edge(constraint, l - 1));

        // return the number of ways to form the array
        return this.isConsistent
                ? this.nFac.modPow(BigInteger.valueOf(this.uf.cc - 1), BigInteger.valueOf(998244353)).intValue()
//                ? (int) Math.pow(this.nFac, cc - 1) % 998244353
                : 0;
    }

    // check the particular cc
    private boolean checkConsistency(int l) {

        // create a visited array
        boolean[] visited = new boolean[this.m + 1];
        // create a stack for the dfs on the connected component
        LinkedList<Integer> bfs = new LinkedList<>();
        // set of nodes in the stack
        HashSet<Integer> contents = new HashSet<>();
        // add the initial element to the stack
        bfs.addFirst(l);
        contents.add(l);

        // as long as the connected component has not been fully explored, do
        while (!bfs.isEmpty()) {
            // pop the next element
            int currNode = bfs.removeLast();
            contents.remove(currNode);
            // if visited already, skip examining the element
            if (visited[currNode]) { continue; }
            // get the neighbours
            ArrayList<Edge> nbs = this.adjList.get(currNode);
            // get the weight of the current node
            int[] currNodeWeight = this.permutations[currNode] == null
                    ? this.id
                    : this.permutations[currNode];
            if (nbs == null) { continue; }
            // loop over the neighbours
            for (Edge nb : nbs) {
                // gc: currNode == neighbour => skip
                // if neighbour visited or is the initial node, don't bother
                if (visited[nb.r] || currNode == nb.r) { continue; }
                // get the edge weight going from the currNode to the curr neighbour
                int[] edgeWeight = nb.weight;
                // init the weight of nb.r
                int[] weight;
                // case where the edge is an outgoing edge
                if (currNode < nb.r) {
                    // if not visited, estimate might not be correct. update the estimate
                    // update the weight of the neighbour node
                    weight = this.op(currNodeWeight, edgeWeight);
                } else { // if incoming edge, do a reverse assignment
                    weight = this.findAssignment(edgeWeight, currNodeWeight);
                }

                // gc: assignment not consistent
                if (visited[nb.r] && !Arrays.equals(weight, this.permutations[nb.r])) {
                    return false;
                }
                this.permutations[nb.r] = weight;

                // add to the stack only if the neighbour has not been visited already, or if it is not already in the stack
                // just add the neighbour to the stack if not added already
                if (!contents.contains(nb.r)) {
                    bfs.addFirst(nb.r);
                    contents.add(nb.r);
                }
            }
            // set visited to true for the current node
            visited[currNode] = true;
        }
        return true;
    }

    private int[] findAssignment(int[] edgeWeight, int[] currNodeWeight) {
        String s = null;
        if (edgeWeight.length != currNodeWeight.length) { s.toCharArray(); }
        // init a hashmap
//        HashMap<Integer, Integer> mapping = new HashMap<>();
        // init comparison array
        int[] compareTo = new int[edgeWeight.length];
        // add the elements to the hashmap => O(n)
        for (int i = 0; i < edgeWeight.length; ++i) {
//            mapping.put(edgeWeight[i], i);
            compareTo[edgeWeight[i] - 1] = i + 1;
        }
        // create the result array. this will be the weight of nb.r => 0(n)
        int[] res = new int[currNodeWeight.length];
        // loop over the currNodeWeight
        for (int j = 0; j < currNodeWeight.length; ++j) {
            // get the current element of the currentNodeWeight
            // get the index it belongs to
            // assign the res at index j to the ind + 1
            res[j] = compareTo[currNodeWeight[j] - 1];
        }
        // return the result at the end
        return res;
    }

    private int[] op(int [] a1, int[] a2) {
        String s = null;
        if (a1.length != a2.length) { s.toCharArray(); }
        int[] res = new int[a1.length];
        for (int i = 0; i < res.length; ++i) {
            res[i] = a2[a1[i] - 1];
        }
        return res;
    }


    // method to get the right element given left and constraint
    public int[] getRight(int[] left, int[] constraint) {
        // create the res array
        int[] b = new int[left.length];
        // loop over b
        for (int i = 0; i < b.length; ++i) {
            // index into b using a[i] - 1, assign to c[i]
            b[left[i] - 1] = constraint[i];
        }
        // return the result
        return b;
    }

    // method to get the left element given right and constraint
    public int[] getLeft(int[] right, int[] constraint) {
        // create mapping of right
        HashMap<Integer, Integer> rightMap = new HashMap<>();
        for (int i = 0; i < right.length; ++i) {
            rightMap.put(right[i], i + 1);
        }
        // create left array
        int[] a = new int[right.length];
        for (int j = 0; j < a.length; ++j) {
            // index into the map with the Ci element, and assign it to Ai
            a[j] = rightMap.get(constraint[j]);
        }
        // return a at the end
        return a;
    }

    private boolean checkDuplicates(int[] constraints) {
        // gc: constraint is not length n
        if (constraints.length != this.n) { return false; }
        // create a boolean array of size n. use the constraint elements to index into it
        boolean[] seen = new boolean[n];
        // count the number of times the element has
        // loop over the constraint
        for (int constraint : constraints) {
            // gc: already seen before => there exist an element that appears more than once
            if (constraint < 1 || constraint > this.n || seen[constraint - 1]) { return false; }
            // else assign the value at the constraint to true
            seen[constraint - 1] = true;
        }
        // return true if the constraints array is a permutation
        return true;
    }
}