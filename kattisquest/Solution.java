import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    // TODO: Include your data structures here
    /**
     * START TREENODE DECLARATION
     *
     * @author kw
     */
    public class TreeNode implements Comparable<TreeNode>{
        /*
         * INIT FIELDS
         */
        private final long energy;
        private final long gold;
        private TreeNode left;
        private TreeNode right;
        private TreeNode parent;
        private int height;

        /**
         * Constructor for the TreeNode class.
         *
         * @author kw
         * @param energy the total energy of the quest
         * @param gold the amount of gold associated with the quest
         *
         */
        public TreeNode(long energy, long gold) {
            this.energy = energy;
            this.gold = gold;
            this.left = null;
            this.right = null;
            this.parent = null;
            this.height = 1;
        }

        /**
         * Override the compareTo method
         *
         * @param otherNode the other node to compare with this
         * @return 1 if this > otherNode, -1 if this < otherNode
         *
         */
        public int compareTo(TreeNode otherNode) {
            if (otherNode == null) {
                return 1;
            }
            if (this.energy > otherNode.energy) {
                return 1;
            } else if (this.energy < otherNode.energy) {
                return -1;
            } else {
                return this.gold >= otherNode.gold
                        ? 1
                        : -1;
            }
        }

        /**
         * Override the toString method.
         *
         * @return the String representation of a quest
         *
         */
        @Override
        public String toString() {
            return "ENERGY: " + this.energy + "\n" +
                    "GOLD: " + this.gold + "\n" +
                    "HEIGHT: " + this.height;
        }
    }
    /**
     * END TREENODE DECLARATION
     */

    /**
     * Init required fields
     */
    private TreeNode root;

    public Solution() {
        // TODO: Construct/Initialise your data structures here
        // keep empty as we do not know what quests Kattis is going to add to the quest tree
    }

    void add(long energy, long value) {
        // TODO: Implement your insertion operation here
        // create new node with the given energy and value
        TreeNode quest = new TreeNode(energy, value);
        // insert into tree
        this.insert(quest);
    }

    long query(long remainingEnergy) {
        // TODO: Implement your query operation here
        // init variable to keep track of the amount og gold earned from the quest
        long totalGold = 0;
        // init variable to keep track of the currentQuest
        TreeNode maxNode;
        // as long as Kattis still has energy to do quests, do:
        while (remainingEnergy > 0) {
            // get root
            TreeNode node = this.root;
            // get the maximum node that can be cleared with the remaining energy
            maxNode = this.searchMax(node, remainingEnergy);
            // guard clause: there is no maxNode
            if (maxNode == null) {
                // just break out of while loop
                break;
            }
            // delete the node away
            this.delete(maxNode);
            // if have task, subtract from remainingEnergy
            remainingEnergy -= maxNode.energy;
            // if have task, add the value of the task to totalGold
            totalGold += maxNode.gold;
        }
        // return the total amount of gold earned from doing the quests
        return totalGold;
    }

    /**
     * Insert method that takes in a TreeNode, and inserts it in the correct
     * position in the quest tree based on the ordering defined in compareTo.
     *
     * @param quest the quest to insert into the quest tree
     *
     */
    public void insert(TreeNode quest) {
        // TODO:
        // case where the root is empty
        if (this.root == null) {
            // assign the quest to the root node
            this.root = quest;
            // insertion has been done => terminate
            return;
        }

        // keep track of the current node to traverse
        TreeNode node = this.root;
        // keep track of the node to rebalance
        TreeNode nodeToRebalance = null;
        // init a previous node to check if, after traversing into
        // a left or right subtree, the node becomes height-unbalanced
        TreeNode previousNode = node;
        // as long as we have not found the key, do:
        while (true) {
            // case where the quest is smaller than the current node
            if (quest.compareTo(node) < 0) {
                // guard clause: the left is null
                if (node.left == null) {
                    // break to insert the quest into the left subtree of the current nodew
                    break;
                }
                // else just traverse the left side of the quest tree
                node = node.left;
            } else { // case where the quest is larger than the current node
                // guard clause: the right is null
                if (node.right == null) {
                    // break to insert the quest into the left subtree of the current node
                    break;
                }
                // else just traverse the right side of the tree
                node = node.right;
            }
            // update the total height of the tree
            ++node.height;

            // check if the tree becomes out of balance
            if (!isBalanced(previousNode) && nodeToRebalance == null) {
                // set the previous node to be the node to rebalance
                nodeToRebalance = previousNode;
            }
            // update the previousNode
            previousNode = node;
        }

        // determine where to insert the tree
        // case where left
        if (quest.compareTo(node) < 0) {
            // insert into left
            node.left = quest;
        } else { // case where right
            // insert into right
            node.right = quest;
        }
        // update the height of the tree
        this.updateHeight(node);
        // update the quest parents
        quest.parent = node;

        // case where the highest node remains unbalanced(quest node was inserted at a new level)
        if (nodeToRebalance != null && !this.isBalanced(nodeToRebalance)) {
            // rotate the out of balance tree
            rotate(nodeToRebalance);
        }
        // recompute height of the tree if needed
        int leftHeight = root.left == null ? 0 : root.left.height;
        int rightHeight = root.right == null ? 0 : root.right.height;
        this.root.height = 1 + Math.max(leftHeight, rightHeight);
    }

    /**
     * Method that takes in a node, and subtracts the height of each node along the path by 1
     *
     * @param node the start point to start subtracting the height
     *
     */
    public void updateHeight(TreeNode node) {
        // init left and right heights
        int leftHeight;
        int rightHeight;
        while (node != null && node != this.root) {
            // get left and right height of the current node
            leftHeight = this.getTreeHeight(node.left);
            rightHeight = this.getTreeHeight(node.right);
            // update height
            node.height = 1 + Math.max(leftHeight, rightHeight);
            // walk up the tree
            node = node.parent;
        }
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
            this.updateHeight(successorParent);
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
        this.updateHeight(successorParent);
        return parent;
    }

    /**
     * Delete method that takes in a remainingEnergy value, and deletes the cluster with the highest energy
     * from the quest tree that is less than the remainingEnergy value. If there are multiple highest energy
     * tasks, choose the one with the highest gold value.
     *
     * @param node the node to delete
     *
     */
    public void delete(TreeNode node) {
        // TODO:
        // guard clause 0: case where the root is null
        if (this.root == null) { return; }
        // guard clause 1: case where the root is trivial
        if (this.root.left == null && this.root.right == null) {
            // delete the whole tree and terminate
            this.root = null;
            return;
        }

        // case where quest node has 0 children
        if (node.left == null && node.right == null) {
            // get the parent as the start point to update heights
            TreeNode parent = node.parent;
            // update the child of the parent
            this.updateChild(node);
            // walk up the tree to update the weights
            this.updateHeight(parent);
        } else if ((node.left != null && node.right == null)
                || (node.left == null && node.right != null)) { // case where the quest node has 1 child
            // get the parent of the tree as the start point to walk up the tree
            TreeNode parent = node.parent;
            // guard clause: the parent is null(i.e. is a root)
            if (parent == null) {
                // get the child
                TreeNode child = node.left != null ? node.left : node.right;
                // update the parent of the child
                child.parent = null;
                // make the root point to the new child
                root = child;
                // terminate early
                return;
            }
            // set the parent's null child to the child of the deleted node
            this.connectChildChildToParent(node, parent);
            // walk up the tree and update the weights
            this.updateHeight(parent);
        } else { // case where the quest node has 2 children
            // get successor of the team node
            TreeNode successor = this.getSuccessor(node);
            // update the child of the parent
            this.swapTeamAndSuccessor(node, successor);
        }
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
        successor.height = team.height;
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

    }

    /**
     * Method that looks for the maximum quest such that remainingEnergy >= quest.energy
     *
     * @param node the node to search in
     * @param remainingEnergy the energy that Kattis has left
     * @return the max quest that Kattis can complete given her energy. returns null if dont
     *         have quest
     *
     */
    public TreeNode searchMax(TreeNode node, long remainingEnergy) {
        // base case 0: node is empty
        if (node == null) {
            // just return null
            return null;
        }
        // base case 1: node is trivial tree
        if (node.left == null && node.right == null) {
            // return the quest only if Kattis can complete it
            return node.energy > remainingEnergy ? null : node;
        }
        // non-base case: node is minimally non-trivial
        // case where the remainingEnergy is smaller than the energy of the current node
        if (remainingEnergy < node.energy) {
            // go left and search for a smaller quest
            return searchMax(node.left, remainingEnergy);
        } else { // case where the remainingEnergy is greater than or equals to the energy of the current node
            // save the maximum
            TreeNode currentNode = node;
            // look for possible larger nodes
            TreeNode rightMax = searchMax(node.right, remainingEnergy);
            // return the maximum of the two nodes
            return currentNode.compareTo(rightMax) < 0
                    // if currentNode smaller, return the rightMax
                    ? rightMax
                    // just return current node if it is larger or rightMax is null
                    : currentNode;
        }
    }
    /**
     * Method that gets the height of a given tree.
     *
     * @param node the given tree
     * @return the height of the given tree
     *
     */
    public int getTreeHeight(TreeNode node) {
        return node == null ? 0 : node.height;
    }

    /**
     * Rotate method that rotates a height-unbalanced tree.
     *
     * @param node the node to perform rotation on
     *
     */
    public void rotate(TreeNode node) {
        // TODO:
        // guard clause: the tree is empty or a trivial tree
        if (node == null || (node.left == null && node.right == null)) { return; }
        // get left height
        int leftHeight = getTreeHeight(node.left);
        // get right height
        int rightHeight = getTreeHeight(node.right);
        // case where left-heavy
        if (leftHeight > rightHeight) {
            // do right rotation
            rightRotate(node);
        } else { // case where right-heavy
            // do left rotation
            leftRotate(node);
        }
    }

    /**
     * Left-rotates a right-heavy tree.
     *
     * @param node the node to perform rotation on
     *
     */
    public void leftRotate(TreeNode node) {
        // TODO:
        // guard clause: node is null
        if (node == null) { return; }
        // get the height of the left and right subtrees of the right subtree
        int leftSubtreeHeight = node.right == null ? 0 : this.getTreeHeight(node.right.left);
        int rightSubtreeHeight = node.right == null ? 0 : this.getTreeHeight(node.right.right);
        // guard clause: the right subtree is left-heavy
        if (leftSubtreeHeight > rightSubtreeHeight) {
            // do a right rotation
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

        // update height of node
        int oldTreeLeftHeight = node.left == null ? 0 : this.getTreeHeight(node.left);
        int oldTreeRightHeight = node.right == null ? 0 : this.getTreeHeight(node.right);
        node.height = 1 + Math.max(oldTreeLeftHeight, oldTreeRightHeight);
        int newTreeLeftHeight = rightSubtree.left == null
                ? 0
                : this.getTreeHeight(rightSubtree.left);
        int newTreeRightHeight = rightSubtree.right == null
                ? 0
                : this.getTreeHeight(rightSubtree.right);
        rightSubtree.height = 1 + Math.max(newTreeLeftHeight, newTreeRightHeight);

        // guard clause: root points to the node
        if (this.root == node) {
            this.root = rightSubtree;
        }
    }

    /**
     * Right-rotates a left-heavy tree
     *
     * @param node the node to perform rotation on
     *
     */
    public void rightRotate(TreeNode node) {
        // TODO:
        // guard clause: node is null
        if (node == null) { return; }
        // get the height of the left and right subtrees of the left subtree
        int leftSubtreeHeight = node.left == null ? 0 : this.getTreeHeight(node.left.left);
        int rightSubtreeHeight = node.left == null ? 0 : this.getTreeHeight(node.left.right);
        // guard clause: the left subtree is right-heavy
        if (rightSubtreeHeight > leftSubtreeHeight) {
            // do a left rotate
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

        // update height of node
        int oldTreeLeftHeight = node.left == null ? 0 : this.getTreeHeight(node.left);
        int oldTreeRightHeight = node.right == null ? 0 : this.getTreeHeight(node.right);
        node.height = 1 + Math.max(oldTreeLeftHeight, oldTreeRightHeight);
        int newTreeLeftHeight = leftSubtree.left == null
                ? 0
                : this.getTreeHeight(leftSubtree.left);
        int newTreeRightHeight = leftSubtree.right == null
                ? 0
                : this.getTreeHeight(leftSubtree.right);
        leftSubtree.height = 1 + Math.max(newTreeLeftHeight, newTreeRightHeight);

        // guard clause: root points to the node
        if (this.root == node) {
            // set the root to the new root node
            this.root = leftSubtree;
        }
    }

    /**
     * Checks whether the given quest tree is height-balanced
     *
     * @param node the node to check for height balance
     * @return true if the tree is height-balanced, false otherwise
     *
     */
    public boolean isBalanced(TreeNode node) {
        // get left subtree height
        int leftHeight = node.left == null ? 0 : node.left.height;
        // get right subtree height
        int rightHeight = node.right == null ? 0 : node.right.height;
        // return whether the absolute difference between the left and right subtree is at most 1
        return Math.abs(leftHeight - rightHeight) <= 1;
    }

    public static void main(String[] args) {
    }
}
