#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Diagnostics {
	private:
		int staffID;
		int patID;
		string description;
		time_t date;

	public:
		/*--------Constructors--------*/
		Diagnostics() {
			staffID = 30200;
			patID = 11019;
			description = "Anemia";
			date = time(&date);
		}

		Diagnostics(int staffID, int patID, string descrip, time_t date) {
			this->staffID = staffID;
			this->patID = patID;
			this->description = descrip;
			this->date = date;
		}

		Diagnostics(const Diagnostics& diagnosis) {
			this->staffID = diagnosis.staffID;
			this->patID = diagnosis.patID;
			this->description = diagnosis.description;
			this->date = diagnosis.date;
		}

		/*------Accessor and Mutators------ */
		int getStaffID() {
			return staffID;
		}

		void setStaffID(int sid) {
			staffID = sid;
		}

		int getPatID() {
			return patID;
		}

		void setPatID(int pid) {
			patID = pid;
		}

		string getDescription() {
			return description;
		}

		void setDescription(string descript) {
			description = descript;
		}

		time_t getDate() {
			return date;
		}

		void setDate(time_t date) {
			this->date = date;
		}

		//Displaying the Diagnosis
		void getDiagnosis() {
			cout << "-------------Diagnosis-------------" << endl;
			cout << "Satff ID: " << staffID << endl;
			cout << "Patient ID: " << patID << endl;
			cout << "Description: " << description << endl;
			cout << "Date: " << ctime(&date) << endl;
		}
};
