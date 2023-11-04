public interface TreeNode {
	public int computeValue(TreeNode t);
}

class Leaf implements TreeNode {
	final int value;

	public Leaf(int value) {
		this.value = value;
	}

	public int computeValue(TreeNode t) {
		return value;
	}
}

class Branch implements TreeNode {
	final TreeNode l, r;
	final int value;
	
	public Branch(int value, TreeNode l, TreeNode r) {
		this.value = value;
		this.l = l;
		this.r = r;
	}

	public int computeValue(TreeNode t) {
		int v1 = computeValue(((Branch)t).l);
		int v2 = computeValue(((Branch)t).r);
		return v1 + v2;
	}
}
