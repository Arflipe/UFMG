class Wrapper<E> {
	private E o;
	
	Wrapper() {
		this.o = null;
	}
	
	Wrapper(E o) {
		this.o = o;
	}
	
	E get() throws EmptyWrapperException {
		if(o == null){
			throw new EmptyWrapperException();
		}
		return o;
	}
}

class EmptyWrapperException extends Exception {
	public EmptyWrapperException() {
		super("Empty Wrapper!");
	}
}

public class Test {
	
	public static void main(String a[]) {
		Wrapper<String> w = new Wrapper<String>();
		try {
			System.out.println(w.get().toString());
		} catch(EmptyWrapperException e) {
			System.out.println(e.getMessage());
		}
	}
}
	