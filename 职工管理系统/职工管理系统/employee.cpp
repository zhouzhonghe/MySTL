#include"employee.h"


//���캯��
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = did;
}

void Employee::showInfo()
{
	cout << "ְ�����: " << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ��ţ��" << endl;
}

string Employee::getDeptName()
{
	return "Ա��";
}