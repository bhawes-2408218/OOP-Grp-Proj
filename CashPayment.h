#pragma once
#include <iostream>
#include "PaymentProcessor.h"
#include "Payment.h"
using namespace std;

class CashPayment : public PaymentProcessor {
	private:
		Payment *payment;

	public:
		//Initializing Payment object with constructor
		CashPayment(Payment *pay){
			payment = pay;
		}

		//Processing the Cash Payment
		bool processPayment(float amount) {
			float total = payment->getTotal();

			cout << "Processing Cash payment of: $" << amount << endl;
			payment->applyPayment(amount);
			return true;
		}

		//Generating the Cash Payment Receipt
		void generateReceipt(float amount) {
			cout << "-----------------CASH RECEIPT----------------" << endl;
			cout << "Cash Amount Paid: $" << amount << endl;
			payment->Status();
			cout << endl;
			cout << "----------------------------------------" << endl;
		}
};