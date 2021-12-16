#include"workerManager.h"
#define FILENAME "empFile.txt"


//����ϵͳ���캯��
WorkerManager::WorkerManager()
{
	//��ʼ������
	//1.���ļ�������ʱ
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�Ϊ��ʱ
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�����,��Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;

	//���ٿռ䣬��������洢Ա����ͬʱ����init��������и�ֵ
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ��id: " << this->m_EmpArray[i]->m_id
			<< "\tְ�������� " << this->m_EmpArray[i]->m_name
			<< "\tְ��ְ�� " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/

	
}



//��ȡ�ļ���Ա������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) //��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 1)
		{
			worker = new manager(id, name, dId);
		}
		else
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index++] = worker;
	}
	ifs.close();
}
			
//��ʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "--------------------------------------" << endl;
	cout << "-----------��ӭʹ��ְ������ϵͳ-------" << endl;
	cout << "-------------0. �˳�����ϵͳ----------" << endl;
	cout << "-------------1. ����ְ����Ϣ----------" << endl;
	cout << "-------------2. ��ʾְ����Ϣ----------" << endl;
	cout << "-------------3. ɾ��ְ����Ϣ----------" << endl;
	cout << "-------------4. �޸�ְ����Ϣ----------" << endl;
	cout << "-------------5. ����ְ����Ϣ----------" << endl;
	cout << "-------------6. ���ձ������----------" << endl;
	cout << "-------------7. ��������ĵ�----------" << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
}

//0.�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//1.���Ա��
void WorkerManager::Add_Emp()
{	
	int addNum = 0;
	cout << "���������ְ������:" << endl;
	cin >> addNum;
	if (addNum > 0)
	{
		//��������¿ռ��С

		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�

		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ������ݿ������¿ռ���

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;
			cin.clear();
			cout << "�������" << i + 1 << " ����ְ�������� " << endl;
			cin >> name;
			cin.clear();
			cout << "��ѡ��ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			cin.clear();

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			//����ְ��ְ�𱣴���������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�
		this->m_EmpArray = newSpace;

		//�����µ�ְ������

		this->m_EmpNum = newSize;

		cout << "��ӳɹ� " << addNum << " ��Ա��" << endl;
		this->save();
		this->m_FileIsEmpty = false;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "��������" << endl;
	}

}

//2.��ʾԱ��
void WorkerManager::show_Em()
{
	//�ж��ļ��Ƿ����

	if (this->m_FileIsEmpty)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//3.ɾ��Ա��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ְ����δ����" << endl;
	}
	else
	{
		cout << "������Ҫɾ��ְ����id" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "��Ա��������" << endl;
		}
		else
		{
			//�����ɾ������Ϊ����ǰ��
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//��������
			this->save();
			cout << "ɾ���ɹ�" << endl;
			system("puase");
			system("cls");
		}
	}
}

//4.�޸�Ա��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "δ����Ա����" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա��id" << endl;
		int id = -1;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ�Ա�����
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��Ա�����������µı�ţ�" << endl;
			cin >> newId;

			cout << "�������µ�����" << endl;
			cin >> newName;

			cout << "�������µĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new boss(newId, newName, dSelect);
				break;
			default:
				cout << "�޸�ʧ��,�������" << endl;
				return;
			}
			//���µ�������
			this->m_EmpArray[ret] = worker;
			this->save();
		}
		else
		{
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
	}
}

//5.����Ա��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų�" << endl;
		cout << "2.��ְ�����ֲ�" << endl;
		int select = 0;
		cin >> select;
		cin.clear();
		if (select == 1)
		{
			cout << "��������" << endl;
			int id = 0;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "�������������" << endl;
			cin >> name;
			cin.clear();
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ��" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
		system("pause");
		system("cls");
	}
}

//6.����
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i; //������Сֵ�����ֵ�±ꣻ
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2) //����
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "��������" << endl;
				}
			}
			//�ж�һ��ʼ�϶� ��Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǣ��������ݣ�
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->show_Em();
	}
	system("pause");
	system("cls");
}

//7.����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	cin.clear();
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] == NULL ? NULL : this->m_EmpArray[i] = NULL;
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" <<endl;
	}
	system("pause");
	system("cls");
}

//���ݱ���ж�Ա���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;  //���������ֶ������ֶ��ͷš�
		this->m_EmpArray = NULL;
	}
}