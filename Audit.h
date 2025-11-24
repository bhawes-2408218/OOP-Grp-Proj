#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Audit {
	private:
		string action;
		string performedBy;
		time_t timestamp;
		string detail;

	public:
		//Constructors
		Audit() {
			action = "Patient Added to System";
			performedBy = "Dr Kingsly";
			timestamp = time(&timestamp);
			detail = "Patient added Successfully";
		}

		Audit(string act, string perform, time_t time, string detail) {
			this->action = act;
			this->performedBy = perform;
			this->timestamp = time;
			this->detail = detail;
		}

		Audit(const Audit& record) {
			action = record.action;
			performedBy = record.performedBy;
			timestamp = record.timestamp;
			detail = record.detail;
		}

		string getAction() {
			return action;
		}

		string getPerformedBy() {
			return performedBy;
		}

		string getTimeStamp() {
			return ctime(&timestamp);
		}

		string getDetail() {
			return detail;
		}

		void recordAction() {
			cout << "Recording Log Entry..." << endl;
			cout << "Record Action Taken: "  << endl;
			cin >> action;
			cout << "Record Who Performed the Action: " << endl;
			cin >> performedBy;
			cout << "Record Time of Action: " << endl;
			cin >> timestamp;
			cout << "Record any Additional Details on the Action: " << endl;
			cin >> detail;
		}

		void Display() {
			cout << "Displaying Audit Record..." << endl;
			cout << "Action Taken: " << action << endl;
			cout << "Performed By: " << performedBy << endl;
			cout << "Time of Action: " << timestamp << endl;
			cout << "Additional Details: " << detail << endl;
		}
};