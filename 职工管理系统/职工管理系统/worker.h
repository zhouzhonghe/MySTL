#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0;

	virtual string getDeptName() = 0;

	int m_id;
	string m_name;
	int m_DeptId;
};