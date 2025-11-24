#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class LabResult {
	private:
		int labResultID;
		string testName;
		string testType;
		string result;
		string measureUnit;
		string resultStatus;
		time_t testDate;
		string performedBy;
		string verifiedBy;
		string staffRemark;

	public:
		/*------------Constructors-----------*/
		LabResult(){
			labResultID = 3211;
			testName = "Quarterly Blood Test";
			testType = "Blood Test";
			result = "Normal";
			measureUnit = "g/dL";
			resultStatus = "Pending";
			testDate = time(&testDate);
			performedBy = "Phlebotomist Jackson";
			verifiedBy = "Dr Walker";
			staffRemark = "No abnormality, everything seems normal";
		}

		LabResult(int id, string name, string type, string result, string unit, string status, time_t date, string performedBy, string verifiedBy, string remark) {
			this->labResultID = id;
			this->testName = name;
			this->testType = type;
			this->result = result;
			this->measureUnit = unit;
			this->resultStatus = status;
			this->testDate = date;
			this->performedBy = performedBy;
			this->verifiedBy = verifiedBy;
			this->staffRemark = remark;
		}

		LabResult(const LabResult& test) {
			labResultID = test.labResultID;
			testName = test.testName;
			testType = test.testType;
			result = test.result;
			measureUnit = test.measureUnit;
			resultStatus = test.resultStatus;
			testDate = test.testDate;
			performedBy = test.performedBy;
			verifiedBy = test.verifiedBy;
			staffRemark = test.staffRemark;
		}

		/*----------Accessors and Mutators-------*/
		int getLabResltID() {
			return labResultID;
		}

		string getTestName() {
			return testName;
		}

		void setTestName(string name) {
			testName = name;
		}

		string getTestType() {
			return testType;
		}

		void setTestType(string type) {
			testType = type;
		}

		string getResult() {
			return result;
		}

		void setResult(string result) {
			this->result = result;
		}

		string getMeasureUnit() {
			return measureUnit;
		}

		void setMeasureUnit(string unit) {
			measureUnit = unit;
		}

		string getResultStatus() {
			return resultStatus;
		}

		void setResultStatus(string status) {
			resultStatus = status;
		}

		time_t getTestDate() {
			return testDate;
		}

		void setTestDate(time_t date) {
			testDate = date;
		}

		string getPerformedBy() {
			return performedBy;
		}

		void setPerformedBy(string performedBy) {
			this->performedBy = performedBy;
		}

		string getVerifiedBy() {
			return verifiedBy;
		}

		void setVerifiedBy(string verifiedBy) {
			this->verifiedBy = verifiedBy;
		}

		string getStaffRemark() {
			return staffRemark;
		}

		void setStaffRemark(string remark) {
			this->staffRemark = remark;
		}

		/*------------Displays Lab Results------------*/
		void viewResult() {
			cout << "-------------Lab Test Report----------" << endl;
			cout << "Lab Result ID: " << labResultID << endl;
			cout << "Test Name: " << testName << endl;
			cout << "Test Type: " << testType << endl;
			cout << "Result: " << result << endl;
			cout << "Unit of Measurement: " << measureUnit << endl;
			cout << "Result Status: " << resultStatus << endl;
			cout << "Test Date: " << ctime(&testDate) << endl;
			cout << "Test Performed By: " << performedBy << endl;
			cout << "Test Verified By: " << verifiedBy << endl;
			cout << "Staff Remark: " << staffRemark << endl;
		}

		/*------------Updates Lab Results------------*/
		void updateResult() {
			cout << "Updating Lab Result..." << endl;
			cout << "Enter new Lab Result: " << endl;
			cin >> result;

			cout << "Enter new Result Status: " << endl;
			cin >> resultStatus;

			cout << "Enter new Test Date: " << endl;
			cin >> testDate;

			cout << "Update Test Performed By: " << endl;
			cin >> performedBy;

			cout << "Update Test Verified By: " << endl;
			cin >> verifiedBy;

			cout << "Enter new Staff Remark: " << endl;
			cin >> staffRemark;

			cout << "Lab Result Updated Successfully!!" << endl;
 		}

};