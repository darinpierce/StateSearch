


/*
* Author : Darin Pierce
* Date Created: 11/22/2023
* Date Modified : 11/24/2023
* Purpose : State clas header for program.


*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
#ifndef STATE_H
#define STATE_H
class State {
private:
	string stateAbrv;
	string stateName;
	string capital;
	int population;
	int year;
	int numCongress;
public:
	State();
	void setStateAbrv(string);
	void setStateName(string);
	void setCapital(string);
	void setPopulation(int);
	void setYear(int);
	void setNumCongress(int);
	string getStateAbrv();
	string getStateName();
	string getCapital();
	int getPopulation();
	int getYear();
	int getNumCongress();
	int computeResidentsPerRep();
	void displayStateInfo();
};
#endif
