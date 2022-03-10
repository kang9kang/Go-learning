package junit;

import org.junit.Test;

import domain.Employee;
import service.NameListService;
import service.TeamExcept;

/**
 * 
 * @Description 对NameListService类的测试
 * @author kang Email:13589130504@163.com
 * @version
 * @date 2022年3月10日下午7:16:19
 *
 */
public class NameListServiceTest {

	@Test
	public void testGetAllEmployees() {
		NameListService service = new NameListService();
		Employee[] employees = service.getAllEmployees();
		for(int i = 0;i < employees.length; i++) {
			System.out.println(employees[i]);
		}
	}
	
	@Test
	public void testGetEmployee() {
		NameListService service = new NameListService();
		
		int id = 101;
		try {
			Employee employee = service.getEmployee(id);
			System.out.println(employee);
		} catch (TeamExcept e) {
			System.out.println(e.getMessage());
		}
	}
}
