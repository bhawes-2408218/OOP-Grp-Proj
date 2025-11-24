#pragma once
#include <iostream>
#include <string>
using namespace std;

class RiskScore {
	private:
		int score;
		string riskLevel;
		//Triage triage;

	public:
		RiskScore() {
			score = 0;
			riskLevel = "Low";
		}

		RiskScore(int rscore, string risklevel) {
			score = rscore;
			riskLevel = risklevel;
		}

		RiskScore(const RiskScore &riskscore) {
			score = riskscore.score;
			riskLevel = riskscore.riskLevel;
		}

		int getScore(){
			return score;
		}

		void setScore(int rscore){
			score = rscore;
		}

		string getRiskLevel() {
			return riskLevel;
		}

		void setRiskLevel(string risklevel) {
			riskLevel = risklevel;
		}

		void recordRiskScore() {



			cout << "Enter Patient's Risk Score: ";
			cin >> score;
		}

		void classifyLevel() {

		}
};