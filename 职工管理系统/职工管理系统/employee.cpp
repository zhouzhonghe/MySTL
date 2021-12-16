#include"employee.h"


//构造函数
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = did;
}

void Employee::showInfo()
{
	cout << "职工编号: " << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位: " << this->getDeptName()
		<< "\t岗位职责：牛马" << endl;
}

string Employee::getDeptName()
{
	return "员工";
}