#pragma once
#include "iostream"
using namespace std;
#include"Cargo.h"
#include"Time.h"
#include"LinkedQueue.h"
#include"LinkedList.h"
#include"PriorityQ.h"
#include"Time.h"

enum UI_MODE
{
	Interactive,
	StepByStep,
	Silent
};

int chooseMode() {
	int num;
	cout << "Please choose the mode you want to run the program in:" << endl;
	cout << "Press 1 for Interactive mode , 2 for StepByStep mode , 3 for silent mode" << endl;
	cin >> num;
	while (num < 1 || num >3) {
		cout << "Invalid number, Please select 1 or 2 or 3 to run the program" << endl;
		cin >> num;
	}
	return num;
}

void outputCargos(LinkedQueue<Cargo*>normal, LinkedQueue<Cargo*>special, PriQ<Cargo*>VIP,string message,bool flag) {
>>>>>>> 0483726036824eec057e3c868de32a12bc764682
	int ncount = QueueCount(normal);
	int scount = QueueCount(special);
	int VIPcount = VIP.PrioQueueCount(VIP);
	cout << ncount + scount + VIPcount << " " << message << ": ";
	cout << "[";
	PrintQueue(normal);
	cout << "] ";
	cout << "(";
	PrintQueue(special);
	cout << ") ";
	cout << "{";
	VIP.PrioQueueCount(VIP);
	cout << "}" << endl;
	if (flag) {
		cout << "----------------------------------------------------" << endl;
		flag = true;
	}
<<<<<<< HEAD
}
=======
}




>>>>>>> 0483726036824eec057e3c868de32a12bc764682
