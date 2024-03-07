import java.util.List;
import java.util.ArrayList;

public class Ex6 {
	public static void main(String a[]) {
		List<Integer> l = new ArrayList<Integer>();
		l.add(1);
		l.add(2);
		l.add(3);
		List<Integer> l2 = l;
		l2.add(4);
		System.out.println(l);
	}
}