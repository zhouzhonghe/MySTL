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
	worker = new boss(1, "����", 1);
	worker->showInfo();*/
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  //�˳�
			wm.ExitSystem();

			break;
		case 1:  //����
			wm.Add_Emp();
			break;
		case 2:  //��ʾ
			wm.show_Em();
			break;
		case 3:  //ɾ��
			wm.Del_Emp();
			break;
		case 4:  //�޸�
			wm.Mod_Emp();
			break;
		case 5:  //����
			wm.Find_Emp();
			break;
		case 6:  //����
			wm.sort_Emp();
			break;
		case 7:  //���
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