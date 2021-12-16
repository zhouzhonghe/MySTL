#include<iostream>
#include<string>
#include<fstream>
#include"workerManager.h"
using namespace std;

#include"employee.h"
#include"worker.h"
#include"boss.h"
#include"manager.h"




int main()
{
	WorkerManager wm;
	int choice = 0;
	/*Worker* worker = NULL;
	worker = new boss(1, "张三", 1);
	worker->showInfo();*/
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  //退出
			wm.ExitSystem();

			break;
		case 1:  //增加
			wm.Add_Emp();
			break;
		case 2:  //显示
			wm.show_Em();
			break;
		case 3:  //删除
			wm.Del_Emp();
			break;
		case 4:  //修改
			wm.Mod_Emp();
			break;
		case 5:  //查找
			wm.Find_Emp();
			break;
		case 6:  //排序
			wm.sort_Emp();
			break;
		case 7:  //清空
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}