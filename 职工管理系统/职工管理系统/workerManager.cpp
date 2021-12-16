#include"workerManager.h"
#define FILENAME "empFile.txt"


//管理系统构造函数
WorkerManager::WorkerManager()
{
	//初始化属性
	//1.当文件不存在时
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在但为空时
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在,但为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在且不为空
	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;

	//开辟空间，创建数组存储员工，同时利用init对数组进行赋值
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工id: " << this->m_EmpArray[i]->m_id
			<< "\t职工姓名： " << this->m_EmpArray[i]->m_name
			<< "\t职工职务： " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/

	
}



//获取文件中员工数量
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

//初始化员工
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
		if (dId == 1) //普通职工
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
			
//显示菜单
void WorkerManager::Show_Menu()
{
	cout << "--------------------------------------" << endl;
	cout << "-----------欢迎使用职工管理系统-------" << endl;
	cout << "-------------0. 退出管理系统----------" << endl;
	cout << "-------------1. 增加职工信息----------" << endl;
	cout << "-------------2. 显示职工信息----------" << endl;
	cout << "-------------3. 删除职工信息----------" << endl;
	cout << "-------------4. 修改职工信息----------" << endl;
	cout << "-------------5. 查找职工信息----------" << endl;
	cout << "-------------6. 按照编号排序----------" << endl;
	cout << "-------------7. 清空所有文档----------" << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
}

//0.退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//1.添加员工
void WorkerManager::Add_Emp()
{	
	int addNum = 0;
	cout << "请输入添加职工数量:" << endl;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算添加新空间大小

		int newSize = this->m_EmpNum + addNum;

		//开辟新空间

		Worker** newSpace = new Worker * [newSize];
		//将原来空间下数据拷贝到新空间下

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << " 个新职工编号： " << endl;
			cin >> id;
			cin.clear();
			cout << "请输入第" << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;
			cin.clear();
			cout << "请选择职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//创建职工职责保存在数组中
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间
		this->m_EmpArray = newSpace;

		//更新新的职工人数

		this->m_EmpNum = newSize;

		cout << "添加成功 " << addNum << " 名员工" << endl;
		this->save();
		this->m_FileIsEmpty = false;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "输入有误" << endl;
	}

}

//2.显示员工
void WorkerManager::show_Em()
{
	//判断文件是否存在

	if (this->m_FileIsEmpty)
	{
		cout << "记录为空" << endl;
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

//3.删除员工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "职工表未创建" << endl;
	}
	else
	{
		cout << "请输入要删除职工的id" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "该员工不存在" << endl;
		}
		else
		{
			//数组的删除本质为数据前移
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数据
			this->save();
			cout << "删除成功" << endl;
			system("puase");
			system("cls");
		}
	}
}

//4.修改员工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "未创建员工表" << endl;
	}
	else
	{
		cout << "请输入要修改的员工id" << endl;
		int id = -1;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到员工编号
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号员工，请输入新的编号：" << endl;
			cin >> newId;

			cout << "请输入新的姓名" << endl;
			cin >> newName;

			cout << "请输入新的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
				cout << "修改失败,输入错误" << endl;
				return;
			}
			//更新到数组中
			this->m_EmpArray[ret] = worker;
			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
	}
}

//5.查找员工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按职工编号查" << endl;
		cout << "2.按职工名字查" << endl;
		int select = 0;
		cin >> select;
		cin.clear();
		if (select == 1)
		{
			cout << "请输入编号" << endl;
			int id = 0;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找姓名" << endl;
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
				cout << "查找失败" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
		system("pause");
		system("cls");
	}
}

//6.排序
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i; //声明最小值或最大值下标；
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2) //降序
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "输入有误" << endl;
				}
			}
			//判定一开始认定 最小值或最大值是不是计算的最小值或最大值，如果不是，交换数据；
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->save();
		this->show_Em();
	}
	system("pause");
	system("cls");
}

//7.清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
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
		cout << "清空成功" <<endl;
	}
	system("pause");
	system("cls");
}

//根据编号判断员工是否存在
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
	ofs.open(FILENAME, ios::out);//写文件

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
		delete[] this->m_EmpArray;  //堆区数据手动开启手动释放。
		this->m_EmpArray = NULL;
	}
}