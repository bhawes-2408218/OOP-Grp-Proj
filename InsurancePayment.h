#pragma once
#include <iostream>
#include "PaymentProcessor.h"
#include "Payment.h"

using namespace std;

class InsurancePayment : public PaymentProcessor {
	private:
		string insuranceProvider;
		string cardNumber;
		Payment *payment;

		//masks all digits of the insurance card number except the last 4 digits
		string maskCard() {
			string last4 = cardNumber.substr(cardNumber.size() - 4);
			return "****-****-****-" + last4;
		}

	public:
		//Initlializing Insurance Payment details with constructor
		InsurancePayment(string provide, string card, Payment *pay) {
			insuranceProvider = provide;
			cardNumber = card;
			payment = pay;
		}

		//Processing the Insurance Payment
		bool processPayment(float amount) {
			//Storing the figures to be use to calculate the final bill
			float total = payment->getTotal();
			float healthCard = payment->getHealthCard(),
			float coverage = payment->getInsuranceCoverage();
			float deductible = payment->getDeductible();

			cout << "------------Processing Insurance payment---------" << endl;
			cout << "Provider: " << insuranceProvider << endl;
			cout << "Card Number : " << cardNumber << endl;
	
			//Insurance Calculation
			float afterHCard = max(0.0f, total - healthCard); //Total after health card amount is deducted
			float insurancePaid = afterHCard * coverage; //Amount the insurance covers
			float remaining = afterHCard - insurancePaid; //Total after the insurance is deducted
			float deductibleAmt = remaining * deductible; //The deductible amount
			float finalTotal = remaining + deductibleAmt; //The total after deductible is added to the total

			cout << "Bill Total: $" << total << endl;
			cout << "Health Card Deduction: $" << healthCard << endl;
			cout << "Insurance Covers: $" << insurancePaid << endl;
			cout << "Deductible: $" << deductibleAmt << endl;
			cout << "Remaining Balance: $" << finalTotal << endl;

			payment->applyPayment(insurancePaid);
			return true;
		}

		//Generating the Insurance Payment Receipt
		void generateReceipt(float amount) {
			cout << "----------------INSURANCE RECEIPT---------------" << endl;
			cout << "Health Insurance Provider: " << insuranceProvider << endl;
			cout << "Health Card Number: " << cardNumber;
			cout << "Amount Covered: $" << amount << endl;
			payment->Status();
			cout << "\n------------------------------------------" << endl;
		}
};