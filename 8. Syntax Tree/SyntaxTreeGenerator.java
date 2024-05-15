class SyntaxTreeNode {
    String value;
    SyntaxTreeNode left, right;

    SyntaxTreeNode(String value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

public class SyntaxTreeGenerator {
    public static void main(String[] args) {
        SyntaxTreeNode root = new SyntaxTreeNode("*");
        root.left = new SyntaxTreeNode("2");
        root.right = new SyntaxTreeNode("+");
        root.right.left = new SyntaxTreeNode("3");
        root.right.right = new SyntaxTreeNode("4");
        printSyntaxTree(root, "", true);
    }

    public static void printSyntaxTree(SyntaxTreeNode node, String prefix, boolean isTail) {
        if (node == null)
            return;
        System.out.println(prefix + (isTail ? "|-- " : "\\-- ") + node.value);

        if (node.left != null || node.right != null) {
            printSyntaxTree(node.left, prefix + (isTail ? "    " : "|   "), false);
            printSyntaxTree(node.right, prefix + (isTail ? "    " : "|   "), true);
        }
    }
}
