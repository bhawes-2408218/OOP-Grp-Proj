#pragma once
#include <iostream>
#include "PaymentProcessor.h"
#include "Payment.h"

class CardPayment : public PaymentProcessor {
	private:
		string cardHolder;
		string cardNumber;
		Payment *payment;

		//Masks all the digits but 4 last digits of the card number
		string maskCard() {
			string last4 = cardNumber.substr(cardNumber.size() - 4);
			return "****-****-****-" + last4;
		}

	public:
		//Constructor
        CardPayment(string cardholder, string cardNum, Payment *pay){
			cardHolder = cardholder;
			cardNumber = cardNum;
			payment = pay;
        }

		//Processing the Card Payment
		bool processPayment(float amount) {
			float total = payment->getTotal();

			cout << "Processing Card payment...." << endl;
			cout << "Card Holder: " << cardHolder << endl;
			cout << "Card Number: " << maskCard() << endl;
			cout << "Amount Charged: " << amount << endl;

			payment->applyPayment(amount);
			return true;
		}

		//Generating the Card Payment Receipt
		void generateReceipt(float amount) {
            cout << "-----------------CARD RECEIPT------------------" << endl;
			cout << "Card Holder: " << cardHolder << endl;
			cout << "Card Number: " << maskCard() << endl;
			cout << "Amount Charged: $" << amount << endl;
			payment->Status();
			cout << endl;
			cout << "------------------------------------------" << endl;
		}
};