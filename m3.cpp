/*
Filename :m3.cpp
Project :Major Assignment
Date :2023-03-10
By :Trisha Vasoya
Description :This program calculates hotel bills of a attendants for a meeting.
*/
//Header file
#include<iostream>
#include<string>
using namespace std;
//Declaring constant variable in global area
const int k = -1;
//Declaring functions
int dayToIndex(string day);
double calculateCostOfRoom(const double roomCost[], int checkInIndex, int checkOutIndex);

int main() {
	//declaring and initializing cont array
	const double roomCost[6] = { 127.50,128.25,130.50,150,150,162.50 };
	string customer;
	string checkInDay;
	string checkOutDay;
	//Declaring and intializing variables
	double customerCost = 0;
	double groupCost = 0;
	int checkInIndex = 0;
	int checkOutIndex = 0;
	//Using loop for input as well as for calculating cost of staying
	for (int i = 0; i < 4; i++) {
		cout << "Enter your name: ";
		if (i != 0) {
			cin.ignore();
		}
		getline(cin, customer);
		//Checking if customer has entered correct input as per requiremnets or not
		if (customer == "") {
			cout << "Missing Name\n\n";
			continue;
		}
		cout << "Enter day of checkin from the given options(sun,mon,tue,wed,thu,fri,sat): ";
		cin >> checkInDay;
		checkInIndex = dayToIndex(checkInDay);
		//Checking if customer has entered correct input as per requiremnets or not
		if (checkInIndex >= 5 || checkInIndex == k) {
			cout << "Invalid Check-in day\n\n";
			continue;
		}
		cout << "Enter day of your checkout from the given options(sun,mon,tue,wed,thu,fri,sat): ";
		cin >> checkOutDay;
		//Checking if customer has entered correct input as per requiremnets or not
		checkOutIndex = dayToIndex(checkOutDay);
		if (checkOutIndex <= 3 || checkOutIndex == k) {
			cout << "Invalid Checkout day\n\n";
			continue;
		}
		if (checkInIndex == checkOutIndex) {
			cout << "Invalid length of stay\n\n";
			continue;
		}
		if (4 == checkOutIndex) {
			cout << "Missing Meeting\n\n";
			continue;
		}
		for (int i = checkInIndex; i < checkOutIndex; i++)
		{
			customerCost += roomCost[i];
		}
		customerCost = calculateCostOfRoom(roomCost, checkInIndex, checkOutIndex);
		groupCost += customerCost;
		cout << "Customer's name: " << customer << endl;
		cout << "Total Cost of Staying: " << customerCost << endl << endl;
	}
	cout << "The total cost of all members accommodations is " << groupCost << endl;
	return 0;
}
/*
* Function   : dayToIndex()
* Description: This function turns the user-entered days into index numbers.
* Parameters : string day: day entered by the user
* Returns    : return value according to day entered by the user.
*/
int dayToIndex(string day) {
	if (day == "sun") {
		return 0;
	}
	else if (day == "mon") {
		return 1;
	}
	else if (day == "tue") {
		return 2;
	}
	else if (day == "wed") {
		return 3;
	}
	else if (day == "thu") {
		return 4;
	}
	else if (day == "fri") {
		return 5;
	}
	else if (day == "sat") {
		return 6;
	}
	else {
		return k;
	}
}
/*
* Function   : calculateCostofRoom()
* Description: This function calculates the total cost of staying.
* Parameters : const double roomCost[6]: cost of room per day.
*   int checkInIndex: checkin day entered by user.
*   int checkOuIndex: checkout day entered by user.
* Returns    : return total cost of staying.
*/
double calculateCostOfRoom(const double roomCost[], int checkInIndex, int checkOutIndex) {
	double totalCost = 0;
	for (int i = checkInIndex; i < checkOutIndex; i++) {
		totalCost += roomCost[i];
	}
	return totalCost;
}
