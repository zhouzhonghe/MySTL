#include"manager.h"


//���캯��
manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = did;
}

void manager::showInfo()
{
	cout << "ְ�����: " << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ�� ��" << endl;
}

string manager::getDeptName()
{
	return "����";
}