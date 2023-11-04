class Avatar {
	public void buy(Knife k) {
		System.out.println("Avatar bought a knife");
	}

	public void buy(Sword s) {
		System.out.println("Avatar bought a sword");
	}
}

class Knife {
	public void isBoughtBy(Avatar a) {
		a.buy(this);
	}

}

class Sword extends Knife {
	public void isBoughtBy(Avatar a) {
		a.buy(this);
	}
}

public class SpiderAv extends Avatar {
	public void buy(Knife k) {
		System.out.println("Spider bought a knife");
	}

	public void buy(Sword s) {
		System.out.println("Spider bought a sword");
	}

	public static void main(String args[]) {
		Avatar a1 = new Avatar();
		Avatar a2 = new SpiderAv();
		SpiderAv sa = new SpiderAv();
		Knife ks = new Sword();
		a1.buy(ks); // Avatar bought a knife
		a2.buy(ks); // Spider bought a knife
		sa.buy(ks); // Spider bought a knife
		ks.isBoughtBy(a1); // Avatar bought a sword
		ks.isBoughtBy(a2); // Spider bought a sword
		ks.isBoughtBy(sa); // Spider bought a sword
	}
}
