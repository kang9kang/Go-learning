package service;

/**
 * 
 * @Description 表示员工的状态
 * @author kang Email:13589130504@163.com
 * @version
 * @date 2022年3月10日下午5:21:15
 *
 */
public class Status {

	private final String NAME;

	public Status(String nAME) {
		super();
		NAME = nAME;
	}

	public String getNAME() {
		return NAME;
	}

	public static final Status FREE = new Status("FREE");
	public static final Status BUSY = new Status("BUSY");
	public static final Status VOCATION = new Status("VOCATION");

	@Override
		public String toString() {
			return NAME;
		}
}
