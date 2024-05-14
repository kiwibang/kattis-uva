import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.*;

public class Solution {
    // TODO: Include your data structures here
    /**
     * TreeNode class.
     *
     * @author kw
     *
     */
    public class TreeNode implements Comparable<TreeNode> {
        /*
         * FIELDS
         */
        int teamNumber;
        int a;
        long b;
        TreeNode left;
        TreeNode right;
        TreeNode parent;
        int weight;

        /**
         * Constructor for a basic TreeNode
         *
         * @param teamNumber the number of the team to set
         *
         */
        public TreeNode(int teamNumber) {
            this.teamNumber = teamNumber;
            // SET DEFAULT VALUES
            this.a = 0;
            this.b = 0L;
            this.left = null;
            this.right = null;
            this.parent = null;
            this.weight = 1;
        }

        /**
         * Method that updates the team's score
         *
         * @param newPenalty the new penalty of the team
         *
         */
        public void updateScore(long newPenalty) {
            ++this.a;
            this.b += newPenalty;
        }

        /**
         * Method that decrements the weight of this by 1.
         */
        public void decrementWeight() {
            --this.weight;
        }

        /**
         * Method that resets the node's parent and child
         *
         */
        public void resetNodePosition() {
            this.parent = null;
            this.left = null;
            this.right = null;
            this.weight = 1;
        }
        /**
         * Override the compareTo method
         */
        @Override
        public int compareTo(TreeNode otherTeam) {
            // case where this team has greater number of problems solved than otherTeam
            if (this.a > otherTeam.a) {
                // return 1 as specified in compareTo
                return 1;
            } else if (this.a < otherTeam.a) {
                return -1;
            } else {
                if (this.b < otherTeam.b) {
                    return 1;
                }
                if (this.b > otherTeam.b) {
                    return -1;
                }
                return -1 * (this.teamNumber - otherTeam.teamNumber);
            }

        }

        /**
         * Override the toString method
         */
        @Override
        public String toString() {
            String str = "==========================\n" +
                    "Team number: " + this.teamNumber + "\n" +
                    "Problems solved: " + this.a + "\n" +
                    "Penalty score: " + this.b + "\n" +
                    "Weight: " + this.weight + "\n" +
                    "==========================";
            return str;
        }
    }

    /**
     * END TREENODE CLASS
     */

    /*
     * FIELDS FOR SOLUTION
     */
    TreeNode[] teams;
    TreeNode root;

    public Solution(int numTeams) {
        // TODO: Construct/Initialise your data structures here
        // get the array of teams
        this.teams = this.getTeamsArray(numTeams);
        // set the initial tree
        this.root = this.buildTree(this.teams);
    }

    public int update(int team, long newPenalty){
        // TODO: Implement your update function here
        // access the team's node through indexing the array => O(1)
        TreeNode currentTeam = this.getTeamNode(team);
        // increment a and update b => O(1)
        currentTeam.updateScore(newPenalty);
        // delete the team node from the tree => O()
        this.deleteTeam(currentTeam);
        // insert on the tree based on the new score of the team
        this.insertTeam(currentTeam);
        // return the rank of team 1
        return this.getRank(this.getTeamNode(1));
    }

    /**
     * Method that gets the rank of a given team
     *
     * @author kw
     * @param node the node of the team to compute the rank
     * @return the rank of the team(minimum 1)
     *
     */
    public int getRank(TreeNode node) {
        // get the number of nodes in the right subtree including the node itself
        int totalNodes = node.right == null ? 1 : node.right.weight + 1;
        // init parent variable
        TreeNode parent = node.parent;
        // init current node variable
        TreeNode currentNode = node;
        // as long as there are nodes to count, do:
        while (parent != null) {
            // case where the parent is greater than the current node
            if (parent.left == currentNode) {
                int rightWeight = parent.right == null ? 0 : parent.right.weight;
                // get the weight of the parent and the parent's right subtree
                totalNodes += 1 + rightWeight;
            }
            // update the child
            currentNode = parent;
            // update the parent
            parent = parent.parent;
        }
        // return the totalNodes at the end
        return totalNodes;
    }

    /**
     * Method that gets the TreeNode of a particular team.
     *
     * @author kw
     * @param team the team number
     * @return treenode of the team
     *
     */
    public TreeNode getTeamNode(int team) {
        return this.teams[this.teams.length - team];
    }

    /**
     * Method that returns the tree of teams
     *
     * @return treenode of teams
     *
     */
    public TreeNode getTeamsTree() {
        return this.root;
    }
    /**
     * Method that takes in a team number, and returns a TreeNode array consisting of each
     * team represented as one node
     *
     * @author kw
     * @param numTeams the number of teams to create nodes for
     * @return a TreeNode[] array where each element TreeNode represents a team
     *
     */
    public TreeNode[] getTeamsArray(int numTeams) {
        // init results array
        TreeNode[] results = new TreeNode[numTeams];
        // loop over the teams
        for (int i = 0; i < numTeams; i++) {
            // create and set a node for each team
            results[numTeams - i - 1] = new TreeNode(i + 1);
        }
        // return the result
        return results;
    }

    /**
     * Method that sets the parent's left or right node to null, depending on whether
     * the child is a left or right child of the parent.
     *
     * @author kw
     * @param node the node whose parent's child node is set to null
     *
     */
    public void updateChild(TreeNode node) {
        // guard clause: node is null
        if (node == null) {
            return;
        }
        // go to parent
        TreeNode parent = node.parent;
        // guard clause: parent is null
        if (parent == null) {
            return;
        }
        // case where child is a left child
        if (parent.left == node) {
            // set the left child to null
            parent.left = null;
        } else { // case where node is a right child
            // set the right child to null
            parent.right = null;
        }
    }

    /**
     * Method that deletes the given team from the tree. Performs rotations if
     * needed.
     *
     * @param team the team to delete from the tree. note that since we have reference to the
     *             parent and the children of the team, we can update the nodes in O(1)
     *
     */
    public void deleteTeam(TreeNode team) {
        // case where the whole root is trivial
        if (root.left == null && root.right == null) {
            // just delete the whole tree
            root = null;
        }
        // case where the team node has 0 children
        if (team.left == null && team.right == null) {
            // get the parent of the tree as the start point to walk up the tree
            TreeNode parent = team.parent;
            // update the child of the parent
            this.updateChild(team);
            // reset the team node
            team.resetNodePosition();
            // walk up the tree and update the weights
            this.decrementWeightsAlongPath(parent);
        } else if ((team.left != null && team.right == null)
                || (team.left == null && team.right != null)) { // case where the team node has 1 child
            // get the parent of the tree as the start point to walk up the tree
            TreeNode parent = team.parent;
            // guard clause: the parent is null(i.e. is a root)
            if (parent == null) {
                // get the child
                TreeNode child = team.left != null ? team.left : team.right;
                // update the parent of the child
                child.parent = null;
                // make the root point to the new child
                root = child;
                // reset node position
                team.resetNodePosition();
                // terminate early
                return;
            }
            // set the parent's null child to the child of the deleted node
            this.connectChildChildToParent(team, parent);
            // walk up the tree and update the weights
            this.decrementWeightsAlongPath(parent);
            // reset the team node
            team.resetNodePosition();
        } else { // case where the team node has 2 children
            // get successor of the team node
            TreeNode successor = this.getSuccessor(team);
            // update the child of the parent
            this.swapTeamAndSuccessor(team, successor);
        }
    }

    /**
     * Method that inserts back a team into the subtree. Where the team will be inserted depends on their score
     *
     * @author kw
     * @param team the team to insert back into the subtree
     *
     */
    public void insertTeam(TreeNode team) {
        // guard clause: the root is empty
        if (root == null) {
            // just assign the root to the team
            root = team;
            // terminate early since we are done
            return;
        }

        // save the root node for traversing
        TreeNode node = this.root;
        // init a node to rebalance. this will be the highest treenode out of balance
        TreeNode nodeToRebalance = null;
        // update the node weight by 1 since we are definitely inserting something inside the tree
        ++node.weight;
        // init a previous node to find the highest ancestor out of balance
        TreeNode previousNode = node;

        // while the key not found, do:
        while (true) {
            // get comparison number
            int compareResult = team.compareTo(node);
            // case where the team to insert is less than the current node value
            if (compareResult < 0) {
                // guard clause: left is null
                if (node.left == null) { break; }
                // update the node to left node
                node = node.left;
            } else if (compareResult > 0) { // case where the team to insert is more than the current node value
                // guard clause: right is null
                if (node.right == null) { break; }
                // update the node to the right node
                node = node.right;
            } else { // case where the team to insert is equal to the current node value
                // save the left subtree
                TreeNode leftChild = node.left;
                // assign the parent of the left child to the team that is inserted
                if (leftChild != null) {
                    leftChild.parent = team;
                }
                // assign the parent of the team to be the current node
                team.parent = node;
                // assign the left child of the team to be the left child of the current node
                team.left = leftChild;
                // update weight of the key
                int leftWeight = node.left == null ? 0 : team.left.weight;
                team.weight = 1 + leftWeight;
                // connect the node left child pointer to team
                node.left = team;
                // rebalance if needed
                if (isOutOfBalance(node)) {
                    this.rotate(node);
                }
                // terminate early
                return;
            }

            // after traversing, update the new node value by 1. This is because we know
            // we are inserting given node into the given tree
            ++node.weight;

            // case where the tree becomes out of balance
            if (isOutOfBalance(previousNode) && nodeToRebalance == null) {
                // record the out of balance tree
                nodeToRebalance = previousNode;
            }
            // update previousNode
            previousNode = node;
        }
        // after loop, we decide where to re-insert the team
        if (team.compareTo(node) < 0) {
            node.left = team;
        } else {
            node.right = team;
        }
        team.parent = node;

        // case where there is a tree that needs rebalancing
        if (nodeToRebalance != null) {
            this.rotate(nodeToRebalance);
        }
    }

    /**
     * Method to determine whether any tree is out of balance. For this, I use
     * a criteria similar to the one in the lecture for height balance, but using weights.
     *
     * @param node the tree to check for balance
     * @return true if the tree is not balanced, false if the tree is balanced
     *
     */
    public boolean isOutOfBalance(TreeNode node) {
        int leftWeight = node.left == null ? 0 : node.left.weight;
        int rightWeight = node.right == null ? 0 : node.right.weight;
        return Math.abs(leftWeight - rightWeight) > 1;
    }

    /**
     * Method that rotates a tree depending on whether it is left or right heavy, as well as determine the
     * case in which it falls under
     *
     * @author kw
     * @param node the node to perform rotation
     *
     */
    public void rotate(TreeNode node) {
        // guard clause: the tree is empty or is a leaf
        if (node == null || (node.left == null && node.right == null)) { return; }
        // determine whether it is left or right heavy
        int leftWeight = node.left == null ? 0 : node.left.weight;
        int rightWeight = node.right == null ? 0 : node.right.weight;
        if (leftWeight > rightWeight) {
            this.rightRotate(node);
        } else {
            this.leftRotate(node);
        }
    }

    /**
     * Method that left-rotates a tree.
     *
     * @param node the tree to perform a left-rotation
     *
     */
    public void leftRotate(TreeNode node) {
        // get weight of the left and right subtrees of the right subtree
        int leftWeight = node.right.left == null ? 0 : node.right.left.weight;
        int rightWeight = node.right.right == null ? 0 : node.right.right.weight;
        // guard clause: the right subtree is left-heavy
        if (leftWeight > rightWeight) {
            // right rotate on the right subtree(trust that the parent will be updated as well)
            rightRotate(node.right);
        }
        // save the left child of the right subtree
        TreeNode leftChildOfRightSubtree = node.right.left;
        // save the right subtree itself
        TreeNode rightSubtree = node.right;

        // assign the original root node's right child to the
        // left child of the right subtree
        node.right = leftChildOfRightSubtree;
        // update the parent of the right subtree
        if (node.right != null) {
            // update the parent of the left subtree
            node.right.parent = node;
        }
        // set the left child of the right subtree to the original root node
        rightSubtree.left = node;
        // set the right subtree parent to be that of the original node(null if original node is root, that is ok.)
        rightSubtree.parent = node.parent;
        // update the parent of the original root node
        node.parent = rightSubtree;
        // update the child of the parent if parent is not null
        if (rightSubtree.parent != null) {
            if (rightSubtree.parent.left == node) {
                rightSubtree.parent.left = rightSubtree;
            } else {
                rightSubtree.parent.right = rightSubtree;
            }
        }
        // update weights of the nodes that shifted
        int nodeLeftWeight = node.left == null ? 0 : node.left.weight;
        int nodeRightWeight = node.right == null ? 0 : node.right.weight;
        node.weight = 1 + nodeLeftWeight + nodeRightWeight;
        int subtreeRightWeight = rightSubtree.right == null ? 0 : rightSubtree.right.weight;
        rightSubtree.weight = 1 + subtreeRightWeight + node.weight;
        // guard clause: root points to the node
        if (this.root == node) {
            // reassign the root to point to the right subtree
            this.root = rightSubtree;
        }
    }

    /**
     * Method that right-rotates a tree.
     *
     * @param node the tree to perform a right-rotation
     *
     */
    public void rightRotate(TreeNode node) {
        // get weight of the left and right subtrees of the left subtree
        int leftWeight = node.left.left == null ? 0 : node.left.left.weight;
        int rightWeight = node.left.right == null ? 0 : node.left.right.weight;
        // guard clause: the left subtree is right-heavy
        if (leftWeight < rightWeight) {
            // left rotate on the left subtree(trust that the parent will be updated as well)
            leftRotate(node.left);
        }
        // save the right child of the left subtree
        TreeNode rightChildOfLeftSubtree = node.left.right;
        // save the left subtree itself
        TreeNode leftSubtree = node.left;

        // assign the original root node's left child to the
        // right child of the left subtree
        node.left = rightChildOfLeftSubtree;
        if (node.left != null) {
            // update the parent of the left subtree
            node.left.parent = node;
        }
        // set the right child of the left subtree to the original root node
        leftSubtree.right = node;
        // set the left subtree parent to be that of the original node(null if original node is root, that is ok.)
        leftSubtree.parent = node.parent;
        // update the parent of the original root node
        node.parent = leftSubtree;
        // update the child of the parent if parent is not null
        if (leftSubtree.parent != null) {
            if (leftSubtree.parent.left == node) {
                leftSubtree.parent.left = leftSubtree;
            } else {
                leftSubtree.parent.right = leftSubtree;
            }
        }
        // update weights of the nodes that shifted
        int nodeLeftWeight = node.left == null ? 0 : node.left.weight;
        int nodeRightWeight = node.right == null ? 0 : node.right.weight;
        node.weight = 1 + nodeLeftWeight + nodeRightWeight;
        int subtreeLeftWeight = leftSubtree.left == null ? 0 : leftSubtree.left.weight;
        leftSubtree.weight = 1 + subtreeLeftWeight + node.weight;
        // guard clause: root points to the node
        if (this.root == node) {
            // reassign the root to point to the left subtree
            this.root = leftSubtree;
        }
    }

    /**
     * Method that gets the successor of a given team node. Credits to Prof. Seth for the wonderful algorithm!
     *
     * @author Prof. Seth Gilbert
     * @author kw
     * @param team the team to look for the successor
     * @return the successor node of the given team
     *
     */
    public TreeNode getSuccessor(TreeNode team) {
        // case where the team has right tree
        if (team.right != null) {
            TreeNode successor = this.searchMinimum(team.right);
            // get successor parent
            TreeNode successorParent = successor.parent;
            // connect the successor child to the parent
            connectChildChildToParent(successor, successorParent);
            // walk up successor parents
            this.decrementWeightsAlongPath(successorParent);
            // delete and reset successor pointers
            successor.resetNodePosition();
            // return the minimum of the right tree
            return successor;
        }
        // case where the team has no right tree
        // set parent
        TreeNode parent = team.parent;
        TreeNode child = team;
        while (parent != null && child == parent.right) {
            child = parent;
            parent = child.parent;
        }
        // get successor parent
        TreeNode successorParent = parent.parent;
        // connect the successor child to the parent
        connectChildChildToParent(parent, successorParent);
        // walk up successor parents
        this.decrementWeightsAlongPath(successorParent);
        // delete and reset successor pointers
        parent.resetNodePosition();
        return parent;
    }

    /**
     * Method that gets the minimum team given a root node
     *
     * @author kw
     * @param team subtree to look for minimum
     *
     */
    public TreeNode searchMinimum(TreeNode team) {
        // guard clause: team is null
        if (team == null) {
            // just return null
            return null;
        }
        // base case: the team is a leaf or the team has no left subtree
        if (team.left == null) {
            // just return the team itself
            return team;
        }
        // non-base case: the tree is more than trivial
        // search the left subtree
        return searchMinimum(team.left);
    }

    /**
     * Method that swaps the team with its successor.
     *
     * @param team the team to replace
     * @param successor the team's successor
     *
     */
    public void swapTeamAndSuccessor(TreeNode team, TreeNode successor) {
        // get the parent of the node
        TreeNode parent = team.parent;
        // case where the deleted node is the parent
        if (parent == null) {
            // pre-emptively set the root to point to the successor
            this.root = successor;
        } else { // parent non-null
            if (parent.left == team) {
                parent.left = successor;
            } else {
                parent.right = successor;
            }
        }
        // assign successor the weight of the team node
        successor.weight = team.weight;
        // save the two children of the child
        TreeNode leftChild = team.left;
        // set the right child as the successor's children
        TreeNode rightChild = team.right;
        // connect the successor to the left and right child
        successor.left = leftChild;
        successor.right = rightChild;
        // update left and right child parent
        if (leftChild != null) {
            leftChild.parent = successor;
        }
        if (rightChild != null) {
            rightChild.parent = successor;
        }
        // set the successor parent
        successor.parent = parent;
        // reset the team node
        team.resetNodePosition();

    }
    /**
     * Method that connects the only child of a child to its parent.
     *
     * @author kw
     * @param child the child of the parent
     * @param parent the parent of the child
     *
     */
    public void connectChildChildToParent(TreeNode child, TreeNode parent) {
        // get the child of the successor
        TreeNode childOfChild = child.left != null
                ? child.left
                : child.right != null
                ? child.right
                : null;
        // check whether the child belongs to left or right
        if (parent.left == child) {
            parent.left = childOfChild;
        } else {
            parent.right = childOfChild;
        }
        if (childOfChild != null) {
            // update parent of child also
            childOfChild.parent = parent;
        }
    }
    /**
     * Method that decrements the weights of the team nodes until it reaches the parent
     *
     * @param startNode the team to start walking up the tree from.
     *
     */
    public void decrementWeightsAlongPath(TreeNode startNode) {
        // while the root is not reached, do:
        while (startNode != null) {
            --startNode.weight;
            // if node out of balance
            if (isOutOfBalance(startNode)) {
                // save the parent first before rotating as the path might change
                TreeNode initialNode = startNode.parent;
                rotate(startNode);
                startNode = initialNode;
            } else {
                startNode = startNode.parent;
            }
        }
    }
    /**
     * Method that takes in a TreeNode[] array and constructs a balanced tree.
     * Used for building the initial tree when Solution() constructor is called.
     *
     * @param teams the teams to construct
     * @return tree associated with the teams, where smaller teamNumber is on the left
     *
     */
    public TreeNode buildTree(TreeNode[] teams) {
        // guard clause: the teams array is empty
        if (teams.length == 0) {
            // return empty tree
            return null;
        }
        // call helper method
        return buildTreeHelper(teams, 0, teams.length - 1);
    }
    /**
     * Method that takes in a TreeNode[] array and builds a tree conisting of the nodes
     * in the low to high index inclusive
     *
     * @author kw
     * @param teams the array of teams to build the tree from
     * @param low   the lower bound of the array to build the tree from,
     *              inclusive
     * @param high  the upper bound of the array to build the tree from,
     *              inclusive
     * @return a tree consisting of the range of nodes specified
     *
     */
    public TreeNode buildTreeHelper(TreeNode[] teams, int low, int high) {
        // guard clause: the teams array is empty
        if (teams.length == 0) {
            // just return empty treeNode
            return null;
        }
        // base case 0: go past the leaves of the tree
        if (low > high) {
            // just return the empty tree
            return null;
        } else if (low == high) { // base case 1: minimally trivial tree
            // just return the leaf node at the given index
            return teams[low];
        } else { // non-base case: more than a trivial tree
            // get the mid element
            int mid = low + (high - low) / 2;
            // get the root node
            TreeNode root = teams[mid];
            // get the left node recursively
            TreeNode left = buildTreeHelper(teams, low, mid - 1);
            // get the right node recursively
            TreeNode right = buildTreeHelper(teams, mid + 1, high);
            // set the left and right subtrees of the root
            root.left = left;
            root.right = right;
            // set the parent of the left and right child
            if (root.left != null) {
                root.left.parent = root;
            }
            if (root.right != null) {
                root.right.parent = root;
            }
            // compute weight of left and right tree
            int leftWeight = left == null ? 0 : left.weight;
            int rightWeight = right == null ? 0 : right.weight;
            // compute weight of overall tree
            root.weight = 1 + leftWeight + rightWeight;
            // once all parameters set, just return the root
            return root;
        }
    }

    /**
     * Print the tree BFS
     */
    public void printTreeBFS(TreeNode root) {
        // non-base case: tree is minimally trivial
        // get a queue, add root inside
        PriorityQueue<TreeNode> printQueue = new PriorityQueue<TreeNode>();
        if (root == null) { return; }
        printQueue.add(root);
        // while queue not empty, do
        while (!printQueue.isEmpty()) {
            // get the next element
            TreeNode currentNode = printQueue.poll();
            // get the next node, and print the root
            System.out.println(currentNode);
            // add left and right child to queue only if not null
            if (currentNode.left != null) {
                printQueue.add(currentNode.left);
            }
            if (currentNode.right != null) {
                printQueue.add(currentNode.right);
            }
        }
    }

    /**
     * Test class
     * @param teams
     */
    public void test(int teams) {
        // init new Solution instance
        Solution test = new Solution(teams);
        // get teams array
        TreeNode[] reality = new TreeNode[teams];
        for (int l = 0; l < teams; l++) {
            reality[l] = test.teams[l];
        }
        //Arrays.sort(reality);
        // init random number generator
        Random rng = new Random();
        while(true) {
            // generate random team to update
            int team = rng.nextInt(teams) + 1;
            // generate random penalty
            long penalty = rng.nextInt(10);
            // update the team with the random penalty
            test.update(team, penalty);
            // after updating, sort the array
            Arrays.sort(reality);
//            for (int j = reality.length - 1; j >= 0; j--) {
//                System.out.println("Team number: " + reality[j].teamNumber);
//                System.out.println("Rank: " + test.getRank(test.getTeamNode(reality[j].teamNumber)));
//                System.out.println("Actual position: " + (reality.length - j));
//                System.out.println("============================================");
//            }
//            System.out.println("TEAM NUMBER: " + team + " | " + "PENALTY: " + penalty);
            System.out.println("soln.update(" + team + ", " + penalty + ");");
            // loop over the array
            for (int i = reality.length - 1; i >= 0; i--) {
                // get the rank of the team
                int rank = test.getRank(test.getTeamNode(reality[i].teamNumber));
                // compare with the actual rank
                if (rank != reality.length - i) {
                    System.out.println("OUTPUT WRONG DUMBASS");
                    for (int p = 0; p < teams; p++) {
                        System.out.println("TEAM NUMBER: " + reality[p].teamNumber);
                        System.out.println("PROBLEMS SOLVED: " + reality[p].a + " | " + "PENALTY: " + reality[p].b);
                        System.out.println("COMPUTED RANK: " + test.getRank(test.getTeamNode(reality[p].teamNumber)));
                        System.out.println("========================================================================");
                    }
                    return;
                }
            }
        }
    }
        // test Solution
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int t;
        int p;
        Solution soln = new Solution(n);
        for (int i = 0; i < m; i++) {
            t = sc.nextInt();
            p = sc.nextInt();
            System.out.println(soln.update(t, p));
        }
    }
}