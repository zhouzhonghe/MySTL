#include"boss.h"


//���캯��
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = did;
}

void boss::showInfo()
{
	cout << "ְ�����: " << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ�� ����" << endl;
}

string boss::getDeptName()
{
	return "�ϰ�";
}