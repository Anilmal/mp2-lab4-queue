#include "TProc.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	TProc h(0.6, 7, 0.3, 3);
	h.RunJob(3);
	cout << "Работа выполнена" << endl;
	cout << "Производительность процессора: " << h.GetProcRate() << endl;
	cout << "Число ядер: " << h.GetCores() << endl;
	cout <<"Тактов на выполнение: "<< h.GetTacts() << endl;
	cout <<"Всего заданий поступило: " <<h.GetJobs() << endl;
	cout <<"Число пропусков:"<< h.GetPasses() << endl;
}