class Animal {
	public void eat() { System.out.println(this + " is eating"); }
	public String toString () { return "Animal"; }
}

class Mammal extends Animal {
	public void suckMilk() { System.out.println(this + " is sucking"); }
	public String toString () { return "Mammal"; }
}

class Dog extends Mammal {
	public void bark() { System.out.println(this + " is barking"); }
	public String toString () { return "Dog"; }
}

public class Zoo {
	public static void main (String args[]) {
		Animal a1 = new Animal();
		Animal a2 = new Mammal();
		Animal a3 = new Dog();
		System.out.println(a1); // 1 Animal
		System.out.println(a2); // 2 Mammal
		System.out.println(a3); // 3 Dog
		a1.eat(); // 4 Animal is eating
		a2.suckMilk(); // 5 Compilation error
		a2.eat(); // 6 Mammal is eating
		Dog d1 = args.length > 1 ? a3 : new Dog(); // 7 Compilation error
		Mammal m1 = d1; // 8 Assignment, does not print
		d1.bark(); // 9 Dog is barking
		m1.suckMilk(); // 10 Dog is sucking
		d1.suckMilk(); // 11 Dog is sucking
		Dog d2 = (Dog)a3; // 12 Assignment, does not print
		a3.bark(); // 13 Compilation error
		d2.bark(); // 14 Dog is barking
		Dog d3 = (Dog)a2; // 15 Runtime error
	}
}