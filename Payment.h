#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Payment {
	protected:
		static map<string, float> serviceFees;
		vector<string> selectedServices;

		int patID;
		int billID;

		float total;
		float healthCard;
		const float insuranceCoverage = 0.80f;
		const float deductible = 0.10;

		float amountPaid;
		string paymentStatus;
		float balance;
		
	public:		
		Payment(){
			patID = 7483;
			billID = 2904; 
			total = 20000.99;
			healthCard = 3000;
			amountPaid = 600.17;
			paymentStatus = "Pending";
			balance = 0;
		}

		Payment(int pID, int bID, float total, float healthcard, float amtPaid, string status, float balance){
			this->patID = pID;
			this->billID = bID;
			this->total = total;
			this->healthCard = healthcard;
			this->amountPaid = amtPaid;
			this->paymentStatus = status;
			this->balance = balance;
		}

		Payment(const Payment& pay) {
			patID = pay.patID;
			billID = pay.billID;
			total = pay.total;
			healthCard = pay.healthCard;
			amountPaid = pay.amountPaid;
			paymentStatus = pay.paymentStatus;
			balance = pay.balance;
		}

		float getTotal() {
			return total;
		}

		float getHealthCard() {
			return healthCard;
		}

		float getInsuranceCoverage() {
			return insuranceCoverage;
		}

		float getDeductible() {
			return deductible;
		}

		float getBalance() {
			return balance;
		}

		//Adds all the services done by the Patient to the Vector by name
		void addService(string serviceName) {
			if (serviceFees.find(serviceName) != serviceFees.end()) {
				selectedServices.push_back(serviceName);
				cout << serviceName << " added to the bill." << endl;
			}
			else {
				cout << "Service not found" << endl;
			}
		}

		//Calculates the Patient's Total 
		void calculateTotal() {
			total = 0;

			for (string service : selectedServices) {
				total += serviceFees[service];
			}

			balance = total;
		}

		//Processes the Patient's Payment and assigns a Payment Status
		void applyPayment(float amount) {
			amountPaid += amount;
			balance -= amount;

			if (balance <= 0) {
				balance = 0;
				paymentStatus = "Paid in full";
			}
			else {
				paymentStatus = "Pending";
				cout << "Returning Balance: $" << balance << endl;
			}
		}

		void Status() const{
			cout << "Remaining Balance: $" << balance << endl;
			cout << "Payment Status: " << paymentStatus << endl;
		}
};
/*declaring the Insurance Coverage and Deductible constants
const float Payment::insuranceCoverage = 0.80f;
const float Payment::deductible = 0.10f; */

//declaring the map of Service names and fees
map<string, float> Payment::serviceFees = { 
	{"Emergency Care", 12000}, 
	{"Doctor's Visit", 4500}, 
	{"Blood Test", 5500}, 
	{"Medication", 6000}, 
	{"X-Ray", 5900} 
}; 