#include"boss.h"


//构造函数
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = did;
}

void boss::showInfo()
{
	cout << "职工编号: " << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位: " << this->getDeptName()
		<< "\t岗位职责： 罗马" << endl;
}

string boss::getDeptName()
{
	return "老板";
}