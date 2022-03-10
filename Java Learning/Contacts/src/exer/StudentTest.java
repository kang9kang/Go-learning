package exer;

public class StudentTest {
	public static void main(String[] args) {
		Student[] stus = new Student[20];
		set(stus);
		print(stus);
		System.out.println("***********");
		search(stus, 3);
		System.out.println("***********");
		sort(stus);
		print(stus);
	}

	/**
	 * 
	 * @Description 赋值学生信息
	 * @author kang Email:13589130504@163.com
	 * @date 2021年9月4日下午10:02:23
	 * @param stus 指定学生组
	 */
	public static void set(Student[] stus) {
		for (int i = 0; i < stus.length; i++) {
			stus[i] = new Student();
			stus[i].number = i + 1;
			stus[i].state = (int) (Math.random() * (6 - 1 + 1) + 1);
			stus[i].score = (int) (Math.random() * (100 - 0 + 1) + 0);
		}
	}

	/**
	 * 
	 * @Description 遍历学生组
	 * @author kang Email:13589130504@163.com
	 * @date 2021年9月4日下午10:01:45
	 * @param stus 指定学生组
	 */
	public static void print(Student[] stus) {
		for (int i = 0; i < stus.length; i++) {
			System.out.println("学号：" + stus[i].number + "，年级：" + stus[i].state + "，成绩：" + stus[i].score);
		}
	}

	/**
	 * 
	 * @Description 查找指定年级的学生
	 * @author kang Email:13589130504@163.com
	 * @date 2021年9月4日下午10:00:55
	 * @param stus  指定学生组
	 * @param state 指定年级
	 */
	public static void search(Student[] stus, int state) {
		for (int i = 0; i < stus.length; i++) {
			if (stus[i].state == state) {
				System.out.println("学号：" + stus[i].number + "，年级：" + stus[i].state + "，成绩：" + stus[i].score);
			}
		}
	}

	/**
	 * 
	 * @Description 根据成绩从小到大排序
	 * @author kang Email:13589130504@163.com
	 * @date 2021年9月4日下午10:05:27
	 * @param stus 指定学生组
	 */
	public static void sort(Student[] stus) {
		for (int i = 0; i < stus.length - 1; i++) {
			for (int j = 0; j < stus.length - 1 - i; j++) {
				if (stus[j + 1].score < stus[j].score) {
					Student temp = stus[j];
					stus[j] = stus[j + 1];
					stus[j + 1] = temp;
				}
			}
		}
	}
}
