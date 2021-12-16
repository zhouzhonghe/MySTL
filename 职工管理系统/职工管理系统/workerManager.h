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
	//记录职工人数
	int m_EmpNum;

	//判断职工是否存在
	int IsExist(int id);

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	void save();

	bool m_FileIsEmpty;
	//统计文件中员工数量
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void show_Em();

	//删除员工
	void Del_Emp();
	//修改员工信息
	void Mod_Emp();

	//查找员工
	void Find_Emp();

	//对职工排序
	void sort_Emp();

	//清空文件
	void Clean_File();

	~WorkerManager();
};