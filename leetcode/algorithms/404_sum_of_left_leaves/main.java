import java.util.Stack;

class SumOfLeftLeaves {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int result = 0;

        if (root.left != null) {
            if (root.left.left == null && root.left.right == null) {
                result += root.left.val;
            } else {
                result += sumOfLeftLeaves(root.left);
            }
        }

        result += sumOfLeftLeaves(root.right);

        return result;
    }


    // Solution
    // Solution 1: Recursive
    public int solution1(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int ans = 0;
        if (root.left != null) {
            if (root.left.left == null && root.left.right == null) {
                ans += root.left.val;
            } else {
                ans += solution1(root.left);
            }
        }

        ans += solution1(root.right);

        return ans;
    }

    // Solution 2: Iterative
    public int solution2(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int ans = 0;

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);

        while (!stack.empty()) {
            TreeNode node = stack.pop();

            if (node.left != null) {
                if (node.left.left == null && node.left.right == null) {
                    ans += node.left.val;
                } else {
                    stack.push(node.left);
                }
            }

            if (node.right != null) {
                if (node.right.left != null || node.right.right != null) {
                    stack.push(node.right);
                }
            }
        }

        return ans;
    }
}
