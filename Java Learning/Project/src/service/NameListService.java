package service;

import domain.Architect;
import domain.Designer;

/**
 * 
 * @Description 负责将Data中的数据封装到Employee[]数组中，同时提供相关操作Emploee[]的方法
 * @author kang Email:13589130504@163.com
 * @version v1.0
 * @date 2022年3月10日下午5:43:13
 *
 */

import domain.Employee;
import domain.Equipment;
import domain.NoteBook;
import domain.PC;
import domain.Printer;
import domain.Programmer;

import static service.Data.*;

public class NameListService {
	private Employee[] employees;

	/**
	 * 给employees及数组元素进行初始化
	 */
	public NameListService() {
		employees = new Employee[EMPLOYEES.length];

		for (int i = 0; i < employees.length; i++) {

			int type = Integer.parseInt(EMPLOYEES[i][0]);
			int id = Integer.parseInt(EMPLOYEES[i][1]);
			String name = EMPLOYEES[i][2];
			int age = Integer.parseInt(EMPLOYEES[i][3]);
			double salary = Double.parseDouble(EMPLOYEES[i][4]);
			Equipment equipment;
			double bonus;
			int stock;

			switch (type) {
			case EMPLOYEE:
				employees[i] = new Employee(id, name, age, salary);
				break;
			case PROGRAMMER:
				equipment = creatEquipment(i);
				employees[i] = new Programmer(id, name, age, salary, equipment);
				break;
			case DESIGNER:
				equipment = creatEquipment(i);
				bonus = Double.parseDouble(EMPLOYEES[i][5]);
				employees[i] = new Designer(id, name, age, salary, equipment, bonus);
				break;
			case ARCHITECT:
				equipment = creatEquipment(i);
				bonus = Double.parseDouble(EMPLOYEES[i][5]);
				stock = Integer.parseInt(EMPLOYEES[i][6]);
				employees[i] = new Architect(id, name, age, salary, equipment, bonus, stock);
				break;
			}
		}
	}

	/**
	 * 
	 * @Description 获取指定index上的员工的设备
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月10日下午6:09:25
	 * @param i
	 * @return
	 */
	private Equipment creatEquipment(int index) {
		int key = Integer.parseInt(EQUIPMENTS[index][0]);

		String modelOrName = EQUIPMENTS[index][1];

		switch (key) {
		case PC:// 21
			String display = EQUIPMENTS[index][2];
			return new PC(modelOrName, display);
		case NOTEBOOK:// 22
			double price = Double.parseDouble(EQUIPMENTS[index][2]);
			return new NoteBook(modelOrName, price);
		case PRINTER:// 23
			String type = EQUIPMENTS[index][2];
			return new Printer(modelOrName, type);
		}
		return null;
	}

	/**
	 * 
	 * @Description 获取当前的所有员工
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月10日下午7:01:44
	 * @return
	 */
	public Employee[] getAllEmployees() {
		return employees;
	}

	/**
	 * 
	 * @Description 获取指定ID的员工
	 * @author kang Email:13589130504@163.com
	 * @date 2022年3月10日下午7:03:09
	 * @param id
	 * @return
	 * @throws TeamExcept
	 */
	public Employee getEmployee(int id) throws TeamExcept {
		for (int i = 0; i < employees.length; i++) {
			if (employees[i].getId() == id) {
				return employees[i];
			}
		}

		throw new TeamExcept("找不到指定员工");
	}
}
