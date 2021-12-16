#include<iostream>
#include<string>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();

	void Show_Menu();

	void ExitSystem();
	//��¼ְ������
	int m_EmpNum;

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	void save();

	bool m_FileIsEmpty;
	//ͳ���ļ���Ա������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void show_Em();

	//ɾ��Ա��
	void Del_Emp();
	//�޸�Ա����Ϣ
	void Mod_Emp();

	//����Ա��
	void Find_Emp();

	//��ְ������
	void sort_Emp();

	//����ļ�
	void Clean_File();

	~WorkerManager();
};