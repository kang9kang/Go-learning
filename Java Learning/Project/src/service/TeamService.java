package service;

import domain.Architect;
import domain.Designer;
import domain.Employee;
import domain.Programmer;

/**
 * 
 * @Description 关于开发团队成员的管理：添加、删除等
 * @author kang Email:13589130504@163.com
 * @version
 * @date 2022年3月12日下午2:27:13
 *
 */
public class TeamService {
	private static int counter = 1;
	private final int MAX_MEMBER = 5;
	private Programmer[] team = new Programmer[MAX_MEMBER];
	private int total = 0;

	public TeamService() {
		super();
	}

	/**
	 * 
	 * @Description 获取开发团队中的成员
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月12日下午2:30:43
	 * @return
	 */
	public Programmer[] getTeam() {
		Programmer[] team = new Programmer[total];
		for (int i = 0; i < team.length; i++) {
			team[i] = this.team[i];
		}
		return team;
	}

	/**
	 * 
	 * @Description 将制定员工添加到开发团队中
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月12日下午2:34:30
	 * @param e
	 * @throws TeamExcept
	 */
	public void addMember(Employee e) throws TeamException {

		if (total >= MAX_MEMBER) {
			throw new TeamException("成员已满，无法添加");
		}

		if (!(e instanceof Programmer)) {
			throw new TeamException("该成员不是开发成员，无法添加");
		}

		if (isExist(e)) {
			throw new TeamException("该员工已在本开发团队中");
		}

		Programmer p = (Programmer) e;
		if ("BUSY".equals(p.getStatus().getNAME())) {
			throw new TeamException("该员工已是某团队成员");
		} else if ("VOCATION".equals(p.getStatus().getNAME())) {
			throw new TeamException("该员工正在休假，无法添加");
		}

		int numOfArch = 0, numOfDes = 0, numOfPro = 0;
		for (int i = 0; i < total; i++) {
			if (team[i] instanceof Architect) {
				numOfArch++;
			} else if (team[i] instanceof Designer) {
				numOfDes++;
			} else if (team[i] instanceof Programmer) {
				numOfPro++;
			}
		}
		if (p instanceof Architect) {
			if (numOfArch >= 1) {
				throw new TeamException("团队中之多有一名架构师");
			}
		} else if (p instanceof Designer) {
			if (numOfDes >= 2) {
				throw new TeamException("团队中之多有两名设计师");
			}
		} else if (p instanceof Programmer) {
			if (numOfPro >= 3) {
				throw new TeamException("团队中之多有三名程序员");
			}
		}

		team[total++] = p;
		p.setStatus(Status.BUSY);
		p.setMemberid(counter++);

	}

	/**
	 * 
	 * @Description 判断指定员工是否存在于现有的开发团队中
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月12日下午2:54:52
	 * @param e
	 * @return
	 */
	private boolean isExist(Employee e) {
		for (int i = 0; i < total; i++) {
			if (team[i].getId() == e.getId()) {
				return true;
			}
		}
		return false;
	}

	/**
	 * 
	 * @Description 从团队中删除成员
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月12日下午3:21:34
	 * @param memberId
	 * @throws TeamException
	 */
	public void removeMember(int memberId) throws TeamException {
		int i = 0;
		for (; i < total; i++) {
			if (team[i].getMemberId() == memberId) {
				team[i].setStatus(Status.FREE);
				break;
			}
		}
		
		if(i == total) {
			throw new TeamException("未找到指定memberId的员工，删除失败");
		}

		for (int j = i + 1; j < total; j++) {
			team[j - 1] = team[j];
		}
		
		team[--total] = null;
	}
}
