#include "TProc.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	TProc h(0.6, 7, 0.3, 3);
	h.RunJob(3);
	cout << "������ ���������" << endl;
	cout << "������������������ ����������: " << h.GetProcRate() << endl;
	cout << "����� ����: " << h.GetCores() << endl;
	cout <<"������ �� ����������: "<< h.GetTacts() << endl;
	cout <<"����� ������� ���������: " <<h.GetJobs() << endl;
	cout <<"����� ���������:"<< h.GetPasses() << endl;
}