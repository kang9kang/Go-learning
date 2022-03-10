package exer;

public class Person {

	String name;
	int age;
	/**
	 * 女性：0
	 * 男性：1
	 */
	int sex;

	public void study() {
		System.out.println("studying");
	}

	public void showAge() {
		System.out.println("age:" + age);
	}

	public int addAge(int i) {
		age += i;
		return age;
	}
}
