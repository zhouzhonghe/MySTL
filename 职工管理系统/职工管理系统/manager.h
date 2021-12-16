#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class manager :public Worker
{
public:
	manager(int id, string name, int did);

	virtual void showInfo();

	virtual string getDeptName();
};
