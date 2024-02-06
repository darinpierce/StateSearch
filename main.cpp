/*
* Author : Darin Pierce
* Date Created: 11/22/2023
* Date Modified : 11/24/2023
* Purpose : Program displays a menu, and either displays a states information with the same abbreviation as the input, or the same year of statehood year as the input year.


*/


#include "state.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
//prototypes
void readStateInfo(ifstream& ifs, vector<State>& stateVec);
void searchByStatehood(vector <State>& stVec, int year, int& startIndex);
int searchByAbrv(vector <State>& stVec, string abrv);
void searchByStatehood(vector <State>&, int, vector<int>&);
void displayMenu();
void displayTableHeader();
int main()
{
	ifstream ifs;
	vector <State> stateVec;
	//other declarations
	bool running = true;
	int menuOption;

	string abrev;
	int index;

	vector<int> indexes;
	int year;
	//read state info into vector
	
	ifs.open("usstates_lab11.txt");
	//if (!ifs.is_open()); could not get to work for some raisin, ignore it for the love of god ignore it
	{
		//cerr << "Could not open file.";
		//return 1;
	}
	readStateInfo(ifs, stateVec);
	//display menu & process input
	do
	{
		
		displayMenu();
		cin >> menuOption;
		if (menuOption == 1)
		{
			cout << "Enter abreviation: ";
			cin >> abrev;
			index = searchByAbrv(stateVec, abrev);
			displayTableHeader();
			
			cout << right << setw(20) << abrev << setw(20) << stateVec.at(index).getStateName() <<
			setw(20) << stateVec.at(index).getCapital()
			<< setw(20) << stateVec.at(index).getPopulation() << setw(11) << stateVec.at(index).getYear() << setw(15) <<
			stateVec.at(index).getNumCongress() << endl;

			

		}
		else if (menuOption == 2)
		{
			cout << "Enter year of statehood: ";
			cin >> year;
			searchByStatehood(stateVec, year, indexes);
			if (!indexes.empty())
			{
				displayTableHeader();
				for (int i = 0; i < indexes.size(); i++)
				{
					stateVec.at(indexes.at(i)).displayStateInfo();
				}
			}
			else
			{
				cout << "No state was created in that year." << endl << endl;
			}
		}
		else if (menuOption == 3)
		{
			running = false;
		}

	} while (running == true);
	system("pause");
	return 0;
}
void displayTableHeader()
{
	//Display table header:
	cout << endl;
	cout << right << setw(20) << "State Abr." << setw(20) << "Name" <<
		setw(20) << "Capital"
		<< setw(20) << "Population" << setw(11) << "Year" << setw(15) <<
		"#Congress" << endl;
	cout << endl;
}
void readStateInfo(ifstream& ifs, vector<State>& stateVec)
{/*string stateAbrv;
	string stateName;
	string capital;
	int population;
	int year;
	int numCongress;*/
	//declarations
	State tmpState;
	string abrv, name, cap, popStr, yStr, congStr;
	int pop, y, cong;
	stringstream ss;

	
		while (!ifs.eof())
		{
			getline(ifs, abrv, ',');
			//read other inputs on a given line using getline
			getline(ifs, name, ',');
			getline(ifs, cap, ',');
			getline(ifs, popStr, ',');
		//read population (need to convert string to int, consider string stream)
		//read year (need to convert string to int, consider string stream)
		//read number of congress (need to convert string to int, consider string stream)
			ss.clear();
			ss << popStr;
			ss >> pop;
			ss.clear();
			getline(ifs, yStr, ',');
			ss << yStr;
			ss >> y;
			ss.clear();
			getline(ifs, congStr);
			ss << congStr;
			ss >> cong;
			tmpState.setStateAbrv(abrv);
			tmpState.setStateName(name);
			tmpState.setCapital(cap);
			tmpState.setPopulation(pop);
			tmpState.setYear(y);
			tmpState.setNumCongress(cong);
			
				//use tmpState.<method> and passing variables into the object through the method
				//tmpState.setStateAbrv(abrv);
			//...
			//add the object to the vector
			stateVec.push_back(tmpState);
		}
		
}
int searchByAbrv(vector <State>& stVec, string abrv)
{
	//return index of object within the vector if found
	for (int i = 0; i < stVec.size(); i++)
	{
		if (stVec.at(i).getStateAbrv() == abrv)
		{
			return i;
		}
	}
	//return -1 if not found
	return -1;
}
void searchByStatehood(vector <State>& stVec, int year, vector<int>&  indexes)
{
	indexes.clear();
	for (int i = 0; i < stVec.size(); i++)
	{
		if (stVec.at(i).getYear() == year)
		{
			indexes.push_back(i);
		}
	}
}
void displayMenu()
{
;
	cout << "1.Search by state abbreviation (e.g. MI). \n2.Search by year of statehood (e.g. 1837). \n3. Exit  program.\n\nPlease enter your choice (1-3):";
	
}
