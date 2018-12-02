#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "time.h"
#include "TJobStream.h"

using namespace std;

class TProc {
private:
	double ProcRate; // производительность процессора
	int count_of_cores = 0;
	double Intense= 0;
	int number_of_executions = 0;
	int number_of_passes = 0;
	int jobs=0;
	double tacts = 0;

public:
	TProc(double Rate,int Cores,double intense,int dones_job)
	{
		if (Rate >= 1)
			throw "Rate is not correct";
		if (intense >= 1)
			throw "Intense is not correct";
		ProcRate = Rate;
		count_of_cores = Cores;
		Intense = intense;
		jobs = dones_job;
	}
	bool IsProcBusy() // процессор занят?
	{
		return  (0.1*(rand() % 9 + 1))< ProcRate;
	}
	void RunJob(int size)// приступить к выполнению  заданий
	{
		TJobStream tmp(Intense);
		TQueue <TJobStream> programs(size);
		for (int i = 0; i < size; i++)
		{
			programs.Add(tmp);
		}
		TQueue <TJobStream> fin_programs(size);
		TQueue <TJobStream> lost_programs(size);
		while (number_of_executions != size)
		{
			if (IsProcBusy())
			{
				
				if (programs.Get().FinishJob())
				{
					number_of_executions++;
					fin_programs.Add(programs.Pop());
				}
				else
				{
					continue;
				}
			}
			else
			{
				number_of_passes++;
				lost_programs.Add(programs.Pop());
			}
				if(programs.IsEmpty())
				{
					int tmp_programs = number_of_passes;
					while(tmp_programs!=0)
					{
						if (lost_programs.Get().FinishJob())
						{
							fin_programs.Add(lost_programs.Pop());
							number_of_executions++;
							tmp_programs--;
						}
						else
							continue;
					}
				}
		}
		while (!fin_programs.IsEmpty())
		{
			tmp = fin_programs.Pop();
			tacts += tmp.GetTacts();
		}
	}
	double GetTacts()
	{
		return tacts;
	}
	int GetJobs()
	{
		return jobs;
	}
	int GetPasses()
	{
		return number_of_passes;
	}
	int GetExecutions()
	{
		return number_of_executions;
	}
	int GetCores()
	{
		return count_of_cores;
	}
	double GetProcRate()
	{
		return ProcRate;
	}
};


