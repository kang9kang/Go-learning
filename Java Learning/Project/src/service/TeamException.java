package service;

/**
 * 
 * @Description 自定义异常类
 * @author kang Email:13589130504@163.com
 * @version
 * @date 2022年3月10日下午7:08:11
 *
 */
public class TeamException extends Exception {
	static final long serialVersionUID = -3387514229948L;

	public TeamException() {
		super();
	}

	public TeamException(String msg) {
		super(msg);
	}
}
