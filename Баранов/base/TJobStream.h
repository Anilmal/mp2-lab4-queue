#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "time.h"

using namespace std;


class TJobStream {
private:
	double JobIntеns; // интенсивность потока задач
	double tacts=0;
public:
	TJobStream()
	{
		JobIntеns =0;
	}
	TJobStream(double Intеns)
	{
		JobIntеns = Intеns;
	}
	bool FinishJob()
	{
		return (0.1*(rand() % 9 + 1))< JobIntеns;
	}
	double GetTacts()
	{
		tacts = 1/JobIntеns;
		return tacts;
	}
};
